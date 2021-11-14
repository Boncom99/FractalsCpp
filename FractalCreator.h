#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include <string>
#include "zoom.h"
using namespace std;
class FractalCreator
{
private:
    /* data */
public:
    FractalCreator(int w, int h);
    void calculateIteration();
    void drawFractal();
    void addZoom(const Zoom &zoom);
    void writeBitMap(string name);
    ~FractalCreator();
};

#endif