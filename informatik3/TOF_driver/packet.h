#ifndef PACKET_H
#define PACKET_H



#include <vector>
#include <cstdint>

#include "sensor_constants.h"
#include "serial.h"



namespace CedesToF
{

    class Packet
    {
    public:
        Packet();
        Packet(Id id);
        Packet(Id id, const std::vector<uint8_t> &data);

        Id getId();
        size_t getLength();
        uint8_t getData(size_t index);
        bool crcIsOkay();

        bool receiveFromSerial(Serial &serial);
        void sendToSerial(Serial &serial);

        void print();

    private:
        uint16_t CalculateCrc();

        StartByte startByte;
        Id id;
        std::vector<uint8_t> data;
        uint16_t crc;
    };

}	// namespace CedesToF



#endif // PACKET_H
