#include <iostream>
#include "FractalCreator.h"
#include "zoom.h"

using namespace std;
using namespace JosepBoncompte;
int main()
{
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.3, RGB(0, 0, 255));
    fractalCreator.addRange(0.5, RGB(0, 200, 255));
    fractalCreator.addRange(1.0, RGB(255, 0, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));

    fractalCreator.run("test.bmp");
    cout << "finished" << endl;

    return 0;
}