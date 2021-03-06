#include "ZoomList.h"
using namespace std;

ZoomList::ZoomList(int w, int h) : m_width(w), m_height(h)
{
}
void ZoomList::add(const Zoom &zoom)
{
    zooms.push_back(zoom);
    m_xCenter = zoom.x;
    m_yCenter = zoom.y;
    //m_xCenter += (zoom.x - m_width / 2) * m_scale;
    //m_yCenter += -(zoom.y - m_height / 2) * m_scale;
    m_scale *= zoom.scale;
}

pair<long double, long double> ZoomList::doZoom(long double x, long double y)
{
    long double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
    double yFractal = (y - m_height / 2) * m_scale + m_yCenter;
    return pair<long double, long double>(xFractal, yFractal);
}
ZoomList::~ZoomList()
{
}