#include <iostream>
#include <fstream>
#include "BitMap.h"
#include "BitMapInfoHeader.h"
#include "BitMapFileHeader.h"
using namespace JosepBoncompte;
using namespace std;

namespace JosepBoncompte
{

    BitMap::BitMap(int width, int height) : m_width(width), m_height(height), m_pPixels(new uint8_t[width * height * 3]{})
    {
    }
    bool BitMap::write(string fileName)
    {
        BitMapFileHeader fileHeader;
        BitMapInfoHeader infoHeader;

        fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + m_width * m_height * 3;
        fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);
        infoHeader.width = m_width;
        infoHeader.height = m_height;

        ofstream file;
        file.open(fileName, ios::out | ios::binary);
        //file.open("images2/" + fileName, ios::out | ios::binary);
        if (!file)
        {
            cout << "cant open file" << endl;
            return false;
        }
        file.write((char *)&fileHeader, sizeof(fileHeader));
        file.write((char *)&infoHeader, sizeof(infoHeader));
        file.write((char *)m_pPixels.get(), m_width * m_height * 3);

        file.close();
        if (!file)
        {
            cout << "cant close file" << endl;
            return false;
        }
        return true;
    }
    void BitMap::setPixel(int x, int y, uint8_t R, uint8_t G, uint8_t B)
    {
        uint8_t *pPixel = m_pPixels.get();
        pPixel += (y * 3) * m_width + (x * 3);
        pPixel[0] = B;
        pPixel[1] = G;
        pPixel[2] = R;
    }

    BitMap::~BitMap()
    {
    }
} // namespace JosepBoncompte
