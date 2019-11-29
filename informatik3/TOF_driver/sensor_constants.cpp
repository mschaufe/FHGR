#include <stdexcept>

#include "sensor_constants.h"



namespace CedesToF
{



    const char *StartByteToString(StartByte startByte)
    {
        switch (startByte)
        {
            case StartByte::SOH:
                return "SOH";
            case StartByte::ACK:
                return "ACK";
            case StartByte::NAK:
                return "NAK";
            default:
                throw std::runtime_error("Unable to convert start byte to string.");
        }
    }



    const char *IdToString(Id id)
    {
        switch (id)
        {
            case Id::NotAllowed:
                return "NotAllowed";
            case Id::GetIdAndVersion:
                return "GetIdAndVersion";

            case Id::SetIntegrationTime:
                return "SetIntegrationTime";
            case Id::SetKindOfData:
                return "SetKindOfData";
            case Id::SetDelayTime:
                return "SetDelayTime";

            case Id::StoreReset:
                return "StoreReset";
            case Id::DistanceImage:
                return "DistanceImage";
            case Id::GreyValueImage:
                return "GreyValueImage";
            case Id::AdditionalData:
                return "AdditionalData";
            case Id::DistanceOnly:
                return "DistanceOnly";

            default:
                throw std::runtime_error("Unable to convert start byte to string.");
        }
    }



    bool IdIsValid(Id id)
    {
        switch (id)
        {
            case Id::NotAllowed:
            case Id::GetIdAndVersion:

            case Id::SetIntegrationTime:
            case Id::SetKindOfData:
            case Id::SetDelayTime:

            case Id::StoreReset:
            case Id::DistanceImage:
            case Id::GreyValueImage:
            case Id::AdditionalData:
            case Id::DistanceOnly:
                return true;

            default:
                return false;
        }
    }



    uint16_t IdToExpectedResponseLength(Id id)
    {
        switch (id)
        {
            case Id::NotAllowed:
                return 0xffff;
            case Id::GetIdAndVersion:
                return 12;

            case Id::SetIntegrationTime:
                return 1;
            case Id::SetKindOfData:
                return 1;
            case Id::SetDelayTime:
                return 2;

            case Id::StoreReset:
                return 0xffff; // Message not specified in documentation
            case Id::DistanceImage:
                return 128;
            case Id::GreyValueImage:
                return 128;
            case Id::AdditionalData:
                return 16;
            case Id::DistanceOnly:
                return 2;

            default:
                return 0xffff;
        }
    }



} // namespace CedesToF
