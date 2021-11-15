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
        vector<int> m_rangeTotals;
        bool m_bGotFirstRange{false};

    private:
        void calculateIteration();
        void calculateTotalIter();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitMap(string name);
        int getRange(int iterations) const;

    public:
        FractalCreator(int w, int h);
        void run(string name);
        void addRange(double rangeEnd, const RGB &rgb);
        void addZoom(const Zoom &zoom);
        ~FractalCreator();
    };

} // namespace JosepBoncompte
#endif