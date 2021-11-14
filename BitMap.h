#ifndef BITMAP_H
#define BITMAP_H
#include <string>
#include <cstdint>
using namespace std;
namespace JosepBoncompte
{
    class BitMap
    {
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixels{nullptr};

    public:
        BitMap(int width, int height);
        void setPixel(int x, int y, uint8_t R, uint8_t G, uint8_t B);

        bool write(string fileName);
        ~BitMap();
    };

} // namespace JosepBoncompte

#endif