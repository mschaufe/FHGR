//
// Created by Marc Schaufelberger on 14.11.19.
//

#include "packet.h"

namespace CedesToF {

    Packet::Packet() {

    }

    Packet::Packet(Id id) {

    }

    Packet::Packet(Id id, const std::vector<uint8_t> &data) {

    }

    Id Packet::getId() {

    }

    size_t Packet::getLength() {
        return 0;
    }

    uint8_t Packet::getData(size_t index) {
        return 0;
    }

    bool Packet::crcIsOkay() {
        return false;
    }

    bool Packet::receiveFromSerial(Serial &serial) {
        serial.readByte();
    }

    void Packet::sendToSerial(Serial &serial) {

    }

    void Packet::print() {

    }

    uint16_t Packet::CalculateCrc() {
        return 0;
    }


}