#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H
#include <cstdint>
using namespace std;
namespace JosepBoncompte
{
    struct BitMapFileHeader
    {
        char header[2]{'B', 'M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };
} // namespace JosepBoncompte

#endif