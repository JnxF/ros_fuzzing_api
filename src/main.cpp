#include <cstdlib>
#include <cassert>
#include "fuzzing_api.hpp"

void fuzz_nth_option(uint8_t fuzzing_option) {
    assert(0 <= fuzzing_option && fuzzing_option <= 13);
    switch (fuzzing_option)
    {
        // bool getBool(bool& b);
        case 0:
            bool getBoolOutput;
            getBool(getBoolOutput);
            break;

        // bool getByte(uint8_t& b);
        case 1:
            uint8_t getByteOutput;
            getByte(getByteOutput);
            break;

        // bool getChar(char& c);
        case 2:
            char getCharOutput;
            getChar(getCharOutput);
            break;

        // bool getFloat32(float& f);
        case 3:
            float getFloat32Output;
            getFloat32(getFloat32Output);
            break;

        // bool getFloat64(double& d);
        case 4:
            double getFloat64Output;
            getFloat64(getFloat64Output);
            break;

        // bool getInt8(int8_t& i);
        case 5:
            int8_t getInt8Output;
            getInt8(getInt8Output);
            break;

        // bool getUInt8(uint8_t& ui);
        case 6:
            uint8_t getUInt8Output;
            getUInt8(getUInt8Output);
            break;

        // bool getInt16(int16_t& i);
        case 7:
            int16_t getInt16Output;
            getInt16(getInt16Output);
            break;

        // bool getUInt16(uint16_t& ui);
        case 8:
            uint16_t getUInt16Output;
            getUInt16(getUInt16Output);
            break;

        // bool getInt32(int32_t& i);
        case 9:
            int32_t getInt32Output;
            getInt32(getInt32Output);
            break;

        // bool getUInt32(uint32_t& ui);
        case 10:
            uint32_t getUInt32Output;
            getUInt32(getUInt32Output);
            break;

        // bool getInt64(int64_t& i);
        case 11:
            int64_t getInt64Output;
            getInt64(getInt64Output);
            break;

        // bool getUInt64(uint64_t& ui);
        case 12:
            uint64_t getUInt64Output;
            getUInt64(getUInt64Output);
            break;

        // bool getString(std::string& s, int8_t size);
        case 13:
            std::string getStringOutputString;
            int8_t getStringSize = 3;
            getString (getStringOutputString, getStringSize);
            break;
    }
}

int main()
{
    uint8_t what_to_fuzz;
    while (getUInt8(what_to_fuzz)) {
        fuzz_nth_option(what_to_fuzz % 14);
    }
}