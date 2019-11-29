#include "serial.h"


#include <string>
#include <sstream>

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

#include <stdlib.h>
#include <syslog.h>
#include <signal.h>

#include <CoreFoundation/CoreFoundation.h>
#include <SystemConfiguration/SystemConfiguration.h>

#include <IOKit/IOKitLib.h>
#include <IOKit/pwr_mgt/IOPMLib.h>
#include <IOKit/ps/IOPSKeys.h>
#include <IOKit/ps/IOPowerSources.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/hid/IOHIDKeys.h>
#include <IOKit/hid/IOHIDLib.h>

#include <IOKit/serial/IOSerialKeys.h>
#include <IOKit/IOBSD.h>

namespace CedesToF
{



    Serial::Serial()
    {
    }



    Serial::~Serial()
    {
        close();
    }



    static speed_t getBaudrateConstant(unsigned int in)
    {
        switch (in)
        {
            case 0:
                return B0;
            case 50:
                return B50;
            case 75:
                return B75;
            case 110:
                return B110;
            case 134:
                return B134;
            case 150:
                return B150;
            case 200:
                return B200;
            case 300:
                return B300;
            case 600:
                return B600;
            case 1200:
                return B1200;
            case 1800:
                return B1800;
            case 2400:
                return B2400;
            case 4800:
                return B4800;
            case 9600:
                return B9600;
            case 19200:
                return B19200;
            case 38400:
                return B38400;
            case 57600:
                return B57600;
            case 115200:
                return B115200;
            case 230400:
                return B230400;
            default:
                break;
        }
        throw std::runtime_error("Invalid baud rate specified.");
    }



    void Serial::open(const std::string &device, unsigned int baudrate)
    {
        using namespace std;
        if (isOpen())
        {
            return;
        }

        // Determine speed
        speed_t speed = getBaudrateConstant(baudrate);

        // Open device
        fd = ::open(device.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
        if (fd == -1)
        {
            throw std::runtime_error(std::string("Opening ") + device +
                                     std::string(" failed: ") + std::string(strerror(errno)));
        }

        struct termios options;
        tcgetattr(fd,&options);
        switch(baudrate)
        {
            case 9600: cfsetispeed(&options,B9600);
                cfsetospeed(&options,B9600);
                break;
            case 19200: cfsetispeed(&options,B19200);
                cfsetospeed(&options,B19200);
                break;
            case 38400: cfsetispeed(&options,B38400);
                cfsetospeed(&options,B38400);
                break;
            default:cfsetispeed(&options,B9600);
                cfsetospeed(&options,B9600);
                break;
        }
        options.c_cflag |= (CLOCAL | CREAD);
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;
        options.c_cflag &= ~CSIZE;
        options.c_cflag |= CS8;
        tcsetattr(fd,TCSANOW,&options);
    }



    bool Serial::isOpen() const
    {
        return (fd != -1);
    }



    void Serial::close()
    {
        if (!isOpen())
        {
            return;
        }
        // Restore old terminal settings
        tcsetattr(fd, TCSANOW, &oldTermiosAttributes);
        // Close device
        ::close(fd);
        fd = -1;
    }



    void Serial::flush()
    {
        tcflush(fd, TCIOFLUSH);
    }



    void Serial::setReadTimeout(unsigned int timeoutMilliseconds)
    {
        if (!isOpen())
        {
            throw std::runtime_error("Serial device is closed.");
        }

        // Check size, unit of c_cc[VTIME] is 0.1s
        struct termios termiosAttributes;
        unsigned int timeMaxMilliseconds = 100 * (1 << 8 * sizeof(termiosAttributes.c_cc[VTIME]));
        if (timeoutMilliseconds > timeMaxMilliseconds)
        {
            std::stringstream ss;
            ss << "Read timeout too large: " << timeoutMilliseconds << " > " <<
               timeMaxMilliseconds << ".";
            throw std::runtime_error(ss.str());
        }

        // Get current terminal settings
        if (tcgetattr(fd, &termiosAttributes) == -1)
            throw std::runtime_error(std::string("Getting current terminal settings failed:  ")
                                     + std::string(strerror(errno)));

        // Set new values
        // See http://man7.org/linux/man-pages/man3/termios.3.html
        if (timeoutMilliseconds != std::numeric_limits<unsigned int>::max())
        {
            // -> MIN == 0, TIME > 0 (read with timeout)
            // The read will be satisfied if a single character is read, or TIME is exceeded
            // (t = TIME * 0.1 s). If TIME is exceeded, no character will be returned.
            // -> MIN == 0, TIME == 0 (polling read)
            termiosAttributes.c_cc[VMIN] = 0;
            termiosAttributes.c_cc[VTIME] = timeoutMilliseconds / 100;
        }
        else
        {
            // -> MIN > 0, TIME == 0 (blocking read)
            termiosAttributes.c_cc[VMIN] = 1;
            termiosAttributes.c_cc[VTIME] = 0;
        }
        tcflush(fd, TCIFLUSH);
        if (tcsetattr(fd, TCSANOW, &termiosAttributes) == -1)
        {
            throw std::runtime_error(std::string("Setting new terminal settings failed:  ")
                                     + std::string(strerror(errno)));
        }
    }



    size_t Serial::readBuffer(uint8_t *buffer, size_t length)
    {
        if (!isOpen())
        {
            throw std::runtime_error("Serial device is closed.");
        }
        return ::read(fd, buffer, length * sizeof(uint8_t));
    }



    void Serial::readBuffer(std::string &buffer, size_t length)
    {
        buffer = std::string(length + 1, '\0');
        size_t numRead = ::read(fd, (void *)buffer.c_str(), length * sizeof(uint8_t));
        if (numRead < length)
        {
            buffer = buffer.substr(0, numRead + 1);
        }
    }



    void Serial::readBuffer(std::vector<uint8_t> &buffer, size_t length)
    {
        if (length == 0)
        {
            return;
        }
        buffer = std::vector<uint8_t>(length, '0');
        size_t numRead = ::read(fd, (void *)buffer.data(), length * sizeof(uint8_t));
        if (numRead < length)
        {
            buffer.erase(buffer.begin() + numRead, buffer.end());
        }
    }



    uint8_t Serial::readByte()
    {
        if (!isOpen())
        {
            throw std::runtime_error("Serial device is closed.");
        }
        uint8_t byte;
        if (::read(fd, &byte, sizeof(uint8_t)) != 1)
        {
            throw std::runtime_error("Read error.");
        }
        return byte;
    }



    size_t Serial::writeBuffer(const uint8_t *buffer, size_t length)
    {
        if (!isOpen())
        {
            throw std::runtime_error("Serial device is closed.");
        }
        return ::write(fd, buffer, length);
    }



    size_t Serial::writeBuffer(const std::string &buffer)
    {
        if (!isOpen())
        {
            throw std::runtime_error("Serial device is closed.");
        }
        return ::write(fd, buffer.c_str(), buffer.size());
    }



    size_t Serial::writeBuffer(const std::vector<uint8_t> &buffer)
    {
        if (!isOpen())
        {
            throw std::runtime_error("Serial device is closed.");
        }
        if (buffer.empty())
            return 0;
        else
            return ::write(fd, buffer.data(), buffer.size());
    }



    size_t Serial::writeByte(uint8_t buffer)
    {
        if (!isOpen())
        {
            throw std::runtime_error("Serial device is closed.");
        }
        return ::write(fd, &buffer, sizeof(uint8_t));
    }



} // namespace CedesToF
