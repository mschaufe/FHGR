#ifndef SENSOR_CONSTANTS_H
#define SENSOR_CONSTANTS_H



namespace CedesToF
{



    enum class StartByte
    {
        SOH = 0x01,
        ACK = 0x06,
        NAK = 0x15
    };

    extern const char *StartByteToString(StartByte startByte);



    enum class Id
    {
        NotAllowed = 0x00,
        GetIdAndVersion = 0x01,

        SetIntegrationTime = 0x20,
        SetKindOfData = 0x21,
        SetDelayTime = 0x22,

        StoreReset = 0x40,
        DistanceImage = 0x41,
        GreyValueImage = 0x42,
        AdditionalData = 0x43,
        DistanceOnly = 0x44
    };

    extern const char *IdToString(Id id);
    extern bool IdIsValid(Id id);
    extern uint16_t IdToExpectedResponseLength(Id id);



    const uint8_t KindOfDataDistanceImage = 0x01;
    const uint8_t KindOfDataGreyImage = 0x02;
    const uint8_t KindOfDataAdditionalData = 0x04;
    const uint8_t KindOfDataDistanceOnly = 0x08;



}	// namespace CedesToF



#endif // SENSOR_CONSTANTS_H
