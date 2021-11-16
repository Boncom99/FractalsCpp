#include <iostream>
#include <thread>
#include "FractalCreator.h"
#include "zoom.h"

using namespace std;
using namespace JosepBoncompte;
int main()
{
    FractalCreator *fractalCreator = new FractalCreator(2400, 1600);
    FractalCreator *fractalCreator1 = new FractalCreator(2400, 1600);
    FractalCreator *fractalCreator2 = new FractalCreator(2400, 1600);
    FractalCreator *fractalCreator3 = new FractalCreator(2400, 1600);
    FractalCreator *fractalCreator4 = new FractalCreator(2400, 1600);

    fractalCreator->addRange(0.0, RGB(0, 0, 0));
    fractalCreator->addRange(0.0005, RGB(255, 0, 0));
    fractalCreator->addRange(1.0, RGB(255, 255, 100));

    fractalCreator1->addRange(0.0, RGB(0, 0, 0));
    fractalCreator1->addRange(0.001, RGB(255, 0, 0));
    fractalCreator1->addRange(1.0, RGB(255, 255, 100));

    fractalCreator2->addRange(0.0, RGB(0, 0, 0));
    fractalCreator2->addRange(0.01, RGB(255, 0, 0));
    fractalCreator2->addRange(1.0, RGB(255, 255, 100));

    fractalCreator3->addRange(0.0, RGB(0, 0, 0));
    fractalCreator3->addRange(0.01, RGB(255, 0, 0));
    fractalCreator3->addRange(1.0, RGB(255, 255, 100));

    fractalCreator4->addRange(0.0, RGB(0, 0, 0));
    fractalCreator4->addRange(0.005, RGB(255, 0, 0));
    fractalCreator4->addRange(1.0, RGB(255, 255, 150));

    fractalCreator1->addZoom(Zoom(1131, 288, 0.1, 1));

    fractalCreator2->addZoom(Zoom(1131, 288, 0.1, 1));
    fractalCreator2->addZoom(Zoom(1460, 915, 0.1, 1));

    fractalCreator3->addZoom(Zoom(1131, 288, 0.1, 1));
    fractalCreator3->addZoom(Zoom(1460, 915, 0.1, 1));
    fractalCreator3->addZoom(Zoom(1122, 1200, 0.1, 1));

    fractalCreator4->addZoom(Zoom(1131, 288, 0.1, 1));
    fractalCreator4->addZoom(Zoom(1460, 915, 0.1, 1));
    fractalCreator4->addZoom(Zoom(1122, 1200, 0.1, 1));
    fractalCreator4->addZoom(Zoom(1491, 771, 0.1, 0.1));
    // thread t1(&FractalCreator::run, fractalCreator, "1.bmp");
    //thread t2(&FractalCreator::run, fractalCreator1, "2.bmp");
    //thread t3(&FractalCreator::run, fractalCreator2, "3.bmp");
    //thread t4(&FractalCreator::run, fractalCreator3, "4.bmp");
    thread t5(&FractalCreator::run, fractalCreator4, "5.bmp");
    //  t1.join();
    //t2.join();
    //t3.join();
    //t4.join();
    t5.join();
    delete fractalCreator;
    delete fractalCreator1;
    delete fractalCreator2;
    delete fractalCreator3;
    delete fractalCreator4;
    return 0;
}