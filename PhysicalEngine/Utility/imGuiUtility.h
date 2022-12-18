#ifndef IMGUIUTILITY_H
#define IMGUIUTILITY_H

// https://github.com/ocornut/imgui/discussions/3862

namespace ImGuiUtility {

    bool ButtonCenteredOnLine(const char *label, float alignment);

    void AlignForWidth(float width, float alignment = 0.5f);

    float CalculateTextWidth(const char *text);

}

#endif //IMGUIUTILITY_H
