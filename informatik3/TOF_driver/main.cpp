#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include "serial.h"
#include "packet.h"


int main()
{
	// Read 300 bytes and dump them as hex numbers on the console
	try
	{
		CedesToF::Serial serial;
		serial.open("/dev/tty.usbserial-1420", 9600);
	/*	for (unsigned int i = 0; i < 500; i++)
		{
			std::cout << std::hex << std::setfill('0') <<
				std::setw(2) << (int)serial.readByte() << " ";
		}*/
	    CedesToF::Packet packet;
        std::cout << serial.readByte();
		serial.close();
	}
	catch (std::exception &ex)
	{
		std::cout << "Error: " << ex.what() << "\n";
	}
	return 0;
}
