#ifndef ZOOM_H
#define ZOOM_H
struct Zoom
{
    long double x{0};
    long double y{0};
    double scale{0.0};
    double percentage{0.1};
    Zoom(long double x, long double y, double scale, double percentage);
    ~Zoom();
};

#endif