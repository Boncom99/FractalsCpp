#ifndef ZOOMLIST_H
#define ZOOMLIST_H
#include <iostream>
#include <vector>
#include <utility>
#include "zoom.h"
using namespace std;
class ZoomList
{
private:
    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1.0};
    int m_width{0};
    int m_height{0};
    vector<Zoom> zooms;

public:
    ZoomList(int w, int h);
    void add(const Zoom &z);
    pair<double, double> doZoom(int x, int y);
    ~ZoomList();
};

#endif