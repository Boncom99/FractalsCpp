#include <iostream>
#include <thread>
#include "FractalCreator.h"
#include "zoom.h"

using namespace std;
using namespace JosepBoncompte;
int main()
{
    FractalCreator fractalCreator;
    fractalCreator.run("test.bmp", 8);
    //int count = 100;
    //FractalCreator fractalCreator[count];
    /* for (int i = 21; i < count; i++)
    {
        fractalCreator[i].addZoom(Zoom(-0.743643900055, 0.131825890901, (double)pow(2, -i), 1.0 + i * 0.01));
        fractalCreator[i].run("ZOOMIN" + to_string(i) + ".bmp", 8);
        cout << "\n"
             << i << endl;
    }*/
    return 0;
}