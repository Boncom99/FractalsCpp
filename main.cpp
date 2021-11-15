
#include "BitMap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace std;
using namespace JosepBoncompte;
int main()
{
    int const height = 600;
    FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(Zoom(295, height - 202, 0.1));
    fractalCreator.addZoom(Zoom(312, height - 304, 0.1));
    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIter();
    fractalCreator.drawFractal();
    fractalCreator.writeBitMap("test.bmp");

    return 0;
}