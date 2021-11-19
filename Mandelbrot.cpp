#include "Mandelbrot.h"
namespace JosepBoncompte
{

    Mandelbrot::Mandelbrot(/* args */)
    {
    }
    int Mandelbrot::getIterations(double x, double y, double scale)
    {
        complex<double> z = 0;
        complex<double> c(x, y);
        int iterations = 0;
        while (iterations < MAX_ITERATIONS * scale)
        {
            z = z * z * z + c;
            if (abs(z) > 2)
            {
                break;
            }

            iterations++;
        }

        return iterations;
    }
    Mandelbrot::~Mandelbrot()
    {
    }

} // namespace JosepBoncompte