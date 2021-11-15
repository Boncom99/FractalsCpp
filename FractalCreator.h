#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <string>
#include <vector>
#include "BitMap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"
using namespace std;
namespace JosepBoncompte
{

    class FractalCreator
    {
    private:
        int m_width;
        int m_height;
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        BitMap m_bitmap;
        ZoomList m_zoomList;
        int m_total{0};

        vector<int> m_ranges;
        vector<RGB> m_colors;

    private:
        void calculateIteration();
        void calculateTotalIter();
        void drawFractal();
        void writeBitMap(string name);

    public:
        FractalCreator(int w, int h);
        void run(string name);
        void addRange(double rangeEnd, const RGB &rgb);
        void addZoom(const Zoom &zoom);
        ~FractalCreator();
    };

} // namespace JosepBoncompte
#endif