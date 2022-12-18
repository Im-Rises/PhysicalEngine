#ifndef SCROLLINGBUFFER_H
#define SCROLLINGBUFFER_H

#include "imgui/imgui.h"
#include <cmath>

// Source: https://github.com/epezent/implot/blob/master/implot_demo.cpp

struct RollingBuffer {
    float Span;
    ImVector<ImVec2> Data;

    RollingBuffer() {
        Span = 10.0f;
        Data.reserve(2000);
    }

    void AddPoint(float x, float y) {
        float xmod = fmodf(x, Span);
        if (!Data.empty() && xmod < Data.back().x)
            Data.shrink(0);
        Data.push_back(ImVec2(xmod, y));
    }
};

#endif //SCROLLINGBUFFER_H
