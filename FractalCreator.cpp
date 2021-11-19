#include "FractalCreator.h"
#include <assert.h>
namespace JosepBoncompte
{
    void FractalCreator::run(string name, int cores)
    {
        calculateIteration(0, m_height);
        calculateTotalIter();
        calculateRangeTotals();
        drawFractal();
        writeBitMap(name);
    }
    void FractalCreator::addRange(double rangeEnd, const RGB &rgb)
    {
        m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        m_colors.push_back(rgb);
        if (m_bGotFirstRange)
        {
            m_rangeTotals.push_back(0);
        }
        m_bGotFirstRange = true;
    }

    int FractalCreator::getRange(int iterations) const
    {
        int range = 0;
        for (int i = 1; i < m_ranges.size(); i++)
        {
            range = i;
            if (m_ranges[i] > iterations)
            {
                break;
            }
        }
        range--;
        assert(range > -1);
        assert(range < m_ranges.size());
        return range;
    }
    void FractalCreator::addZoom(const Zoom &zoom)
    {
        m_zoomList.add(zoom);
    }
    FractalCreator::FractalCreator(int w, int h) : m_width(w), m_height(h),
                                                   m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
                                                   m_fractal(new int[m_width * m_height]{0}),
                                                   m_bitmap(m_width, m_height),
                                                   m_zoomList(m_width, m_height)
    {

        m_zoomList.add(Zoom(0, 0, 4.0 / m_width, 0.05));

        addRange(0.0, RGB(0, 0, 0));
        addRange(0.0055, RGB(255, 0, 0));
        addRange(0.01, RGB(255, 100, 0));
        addRange(1.0, RGB(255, 255, 150));
    }
    FractalCreator::FractalCreator() : m_width(1200), m_height(800),
                                       m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
                                       m_fractal(new int[m_width * m_height]{0}),
                                       m_bitmap(m_width, m_height),
                                       m_zoomList(m_width, m_height)
    {

        m_zoomList.add(Zoom(0, 0, 2.0 / m_width, 0.05));

        addRange(0.0, RGB(0, 0, 0));
        addRange(0.005, RGB(255, 0, 0));
        addRange(0.015, RGB(255, 80, 0));
        addRange(1.0, RGB(255, 255, 150));
    }

    void FractalCreator::calculateIteration(int min, int max)
    {
        double percentage = (m_zoomList.zooms.back()).percentage;
        for (int y = min; y < max; y++)
        {
            cerr << "\r lines " << y << flush;
            for (int x = 0; x < m_width; x++)
            {
                pair<long double, long double> coords = m_zoomList.doZoom(x, y);
                int iterations = Mandelbrot::getIterations(coords.first, coords.second, percentage);
                m_fractal[y * m_width + x] = iterations;
                if (iterations != Mandelbrot::MAX_ITERATIONS * percentage)
                {
                    m_histogram[iterations]++;
                }
            }
        }
    }

    void FractalCreator::calculateRangeTotals()
    {
        int rangeIndex = 0;
        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            int pixels = m_histogram[i];
            if (i >= m_ranges[rangeIndex + 1])
            {
                rangeIndex++;
            }
            m_rangeTotals[rangeIndex] += pixels;
        }
    }
    void FractalCreator::calculateTotalIter()
    {

        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
        {
            m_total += m_histogram[i];
        }
    }
    void FractalCreator::drawFractal()
    {
        double percentage = (m_zoomList.zooms.back()).percentage;
        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                int iterations = m_fractal[y * m_width + x];
                int range = getRange(iterations);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                RGB &startColor = m_colors[range];
                RGB &endColor = m_colors[range + 1];
                RGB colorDiff = endColor - startColor;
                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                if (iterations != Mandelbrot::MAX_ITERATIONS * percentage)
                {
                    int TotalPixels = 0;
                    for (int i = rangeStart; i <= iterations; i++)
                    {
                        TotalPixels += m_histogram[i];
                    }
                    red = startColor.r + colorDiff.r * (double)TotalPixels / rangeTotal;
                    green = startColor.g + colorDiff.g * (double)TotalPixels / rangeTotal;
                    blue = startColor.b + colorDiff.b * (double)TotalPixels / rangeTotal;
                }
                m_bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }

    void FractalCreator::writeBitMap(string name)
    {
        m_bitmap.write(name);
    }
    FractalCreator::~FractalCreator()
    {
    }

} // namespace JosepBoncompte