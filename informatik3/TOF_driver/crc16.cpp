#include "crc16.h"



namespace CedesToF
{



    Crc16::Crc16()
    {
    }



    void Crc16::reset()
    {
        crc = 0xffff;
    }



    void Crc16::update(uint8_t byte)
    {
        uint16_t x = ((crc >> 8) & 0xff) ^ byte;
        x ^= x >> 4;
        crc = (crc << 8) ^ (x << 12) ^ (x <<5) ^ x;

        /*
        // Original implementation from CEDES
        crc = (uint8_t)(crc >> 8) | (crc << 8);
        crc ^= byte;
        crc ^= (uint8_t)(crc & 0xff) >> 4;
        crc ^= (crc << 8) << 4;
        crc ^= ((crc & 0xff) << 4) << 1;
        */
    }



    uint16_t Crc16::get() const
    {
        return crc;
    }



    uint16_t CalculateCrc16(const std::vector<uint8_t> &buffer)
    {
        Crc16 crc;
        for (size_t i = 0; i < buffer.size(); i++)
            crc.update(buffer[i]);
        return crc.get();
    }



    uint16_t CalculateCrc16(const std::string &buffer)
    {
        Crc16 crc;
        for (size_t i = 0; i < buffer.size(); i++)
            crc.update(buffer[i]);
        return crc.get();
    }



} // namespace CedesToF
