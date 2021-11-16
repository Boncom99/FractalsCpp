#ifndef ZOOM_H
#define ZOOM_H
struct Zoom
{
    int x{0};
    int y{0};
    double scale{0.0};
    double percentage{0.1};
    Zoom(int x, int y, double scale, double percentage);
    ~Zoom();
};

#endif