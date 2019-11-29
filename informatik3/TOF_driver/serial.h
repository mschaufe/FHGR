#ifndef SERIAL_H
#define SERIAL_H



#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>
#include <termios.h>
#include <vector>



namespace CedesToF
{



/** \brief Class for accessing a serial device under Linux
  */
    class Serial
    {
    public:

        /// Constructor
        Serial();
        /** \brief Destructor
          * Closes device if still open upon destruction
          */
        ~Serial();

        /** \brief Open serial device
          * \param device String of device node representing serial device
          * \param baudrate Speed of serial device in Baud
          *
          * Typical device specifications are "/dev/ttyS0" or "/dev/ttyUSB0".
          *
          * Baud rate must be canonical, max baud rate is 4000000 baud.
          */
        void open(const std::string &device, unsigned int baudrate);
        /** \brief Check if serial device is open
          * \return `true` if device is open
          */
        bool isOpen() const;
        /** \brief Close serial device
          */
        void close();

        void flush();

        /** \brief Set read timeout for serial device
          * \param timeoutMilliseconds Read timeout in milliseconds, see notes below
          *
          * For `timeoutMilliseconds == 0`, it is checked if the device has data
          * available. If this is the case the data us returned, otherwise a
          * read timeout is triggered. This is also called **polling** mode.
          *
          * For `0 < timeoutMilliseconds < std::numeric_limits<unsigned int>::max()`
          * The timeout is set according to the timeout parameter. This is also
          * called **timeout** mode.
          *
          * For `timeoutMilliseconds == std::numeric_limits<unsigned int>::max()`
          * the read timeout is set to infinite. This is also called **blocking** mode.
          *
          * Default configuration of the serial device is "blocking".
          *
          * Method throws an exception if called on a closed device.
          */
        void setReadTimeout(unsigned int timeoutMilliseconds);
        /** \brief Read a number of bytes from the serial device
          * \param buffer Target buffer to store the data read
          * \param length Number of bytes to read
          * \return Number of bytes read
          *
          * The caller has to provide a buffer of sufficient size.
          *
          * The read is a blocking read: the function does not return
          * until the data was read or the read timeout was reached.
          *
          * Upon read timeout, the method may return less data than requested.
          *
          * Method throws an exception if called on a closed device.
          */
        size_t readBuffer(uint8_t *buffer, size_t length);
        /** \brief Read a number of bytes from the serial device
          * \param buffer Target buffer to store the data read
          * \param length Number of bytes to read
          *
          * The read is a blocking read: the function does not return
          * until the data was read or the read timeout was reached.
          *
          * Upon read timeout, the method may return less data than requested.
          *
          * Method throws an exception if called on a closed device.
          */
        void readBuffer(std::string &buffer, size_t length);
        /** \brief Read a number of bytes from the serial device
          * \param buffer Target buffer to store the data read
          * \param length Number of bytes to read
          *
          * The read is a blocking read: the function does not return
          * until the data was read or the read timeout was reached.
          *
          * Upon read timeout, the method may return less data than requested.
          *
          * Method throws an exception if called on a closed device.
          */
        void readBuffer(std::vector<uint8_t> &buffer, size_t length);
        /** \brief Read a single byte from serial device
          * \return Byte that was read
          *
          * The read is a blocking read: the function does not return
          * until the data was read or the read timeout was reached.
          *
          * Upon read timeout, this method throws an exception.
          *
          * Method throws an exception if called on a closed device.
          */
        uint8_t readByte();

        /** \brief Write contents of buffer to serial device
          * \param buffer Pointer to buffer
          * \param length Number of bytes to write
          * \return Number of bytes written
          *
          * Method throws an exception if called on a closed device.
          */
        size_t writeBuffer(const uint8_t *buffer, size_t length);
        /** \brief Write contents of buffer to serial device
          * \param buffer Pointer to buffer
          * \return Number of bytes written
          *
          * Method throws an exception if called on a closed device.
          */
        size_t writeBuffer(const std::string &buffer);
        /** \brief Write contents of buffer to serial device
          * \param buffer Pointer to buffer
          * \return Number of bytes written
          *
          * Method throws an exception if called on a closed device.
          */
        size_t writeBuffer(const std::vector<uint8_t> &buffer);
        /** \brief Write a single byte to serial device
          * \param buffer Byte to write
          * \return Number of bytes written
          *
          * Method throws an exception if called on a closed device.
          */
        size_t writeByte(uint8_t buffer);

    private:

        /// File desciptor of serial device
        int fd = -1;
        /// Old attributes of serial device to be restored when releasing device
        struct termios oldTermiosAttributes;
    };



} // namespace CedesToF



#endif	// SERIAL_H
