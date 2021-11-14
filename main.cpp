#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "BitMap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace std;
using namespace JosepBoncompte;
int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;
    BitMap bitmap(WIDTH, HEIGHT);
    ZoomList zoomlist(WIDTH, HEIGHT);
    zoomlist.add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));
    zoomlist.add(Zoom(295, HEIGHT - 202, 0.1));
    zoomlist.add(Zoom(312, HEIGHT - 304, 0.1));
    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            pair<double, double> coords = zoomlist.doZoom(x, y);
            int iterations = Mandelbrot::getIterations(coords.first, coords.second);
            fractal[y * WIDTH + x] = iterations;
            if (iterations != Mandelbrot::MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    {
        total += histogram[i];
    }
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            uint8_t red = 0;
            uint8_t green = 0;

            uint8_t blue = 0;

            int iterations = fractal[y * WIDTH + x];
            if (iterations != Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;
                for (int i = 0; i < iterations; i++)
                {
                    hue += (double)histogram[i] / total;
                }
                green = hue * 255;
                red = pow(255, hue);
            }
            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test.bmp");

    cout << "Finished." << endl;
    return 0;
}