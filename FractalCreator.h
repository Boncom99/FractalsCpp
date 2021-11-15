#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <string>
#include "BitMap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
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

    public:
        FractalCreator(int w, int h);
        void calculateIteration();
        void calculateTotalIter();
        void drawFractal();
        void addZoom(const Zoom &zoom);
        void writeBitMap(string name);
        ~FractalCreator();
    };

} // namespace JosepBoncompte
#endif