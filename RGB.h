#ifndef RGB_H
#define RGB_H
namespace JosepBoncompte
{

    struct RGB
    {
        double r;
        double g;
        double b;

        RGB(double r, double g, double b);
    };
    RGB operator-(const RGB &first, const RGB &second);

} // namespace JosepBoncompte
#endif