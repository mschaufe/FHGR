#ifndef CRC16_H
#define CRC16_H



#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>



namespace CedesToF
{

/** \brief Class for calculating 16-bit checksums
  *
  * <table>
  * <caption id="multi_row">Properties</caption>
  * <tr><td>Name<td>CRC-CCITT
  * <tr><td>Bits<td>16
  * <tr><td>Used in<td>XMODEM CRC, HDLC, X.25
  * <tr><td>Polynomial<td>X^16 + X^12 + X^5 + 1
  * <tr><td>Start value<td>0xffff
  * </table>
  *
  * When an object of this class is instantiated it can be updated
  * with new incoming data and always provides a checksum of the
  * data that has been fed in so far.
  *
  * The implementation does not use lookup tables.
  */
    class Crc16
    {
    public:
        /// Constructor
        Crc16();

        /** \brief Resetting CRC object
          *
          * Restores object to initial state
          */
        void reset();
        /** \brief Update CRC with new data
          * \param byte Data byte
          */
        void update(uint8_t byte);
        /** \brief Get CRC for data that has been fed into the class with the update method
          * \return CRC value
          */
        uint16_t get() const;

    private:

        /// Current CRC, initialized with start value
        uint16_t crc = 0xffff;
    };



/** \brief Calculate CRC for buffer based on Crc16 class
  * \param buffer Buffer provided by the user
  * \return CRC value
  */
    extern uint16_t CalculateCrc16(const std::vector<uint8_t> &buffer);

/** \brief Calculate CRC for buffer based on Crc16 class
  * \param buffer Buffer provided by the user
  * \return CRC value
  */
    extern uint16_t CalculateCrc16(const std::string &buffer);



} // namespace CedesToF



#endif // CRC16_H
