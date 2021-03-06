#ifndef MANDELBROT_H
#define MANDELBROT_H
#include <iostream>
#include <complex>
using namespace std;
namespace JosepBoncompte
{

    class Mandelbrot
    {
    public:
        static const int MAX_ITERATIONS = 10000;

    public:
        Mandelbrot();
        static int getIterations(double x, double y, double scale);
        ~Mandelbrot();
    };
} // namespace JosepBoncompte

#endif