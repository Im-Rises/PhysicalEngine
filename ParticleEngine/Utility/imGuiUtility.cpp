#include "imGuiUtility.h"

#include "imgui/imgui.h"

bool ImGuiUtility::ButtonCenteredOnLine(const char *label, float alignment) {
    ImGuiStyle &style = ImGui::GetStyle();

    float size = ImGui::CalcTextSize(label).x + style.FramePadding.x * 2.0f;
    float avail = ImGui::GetContentRegionAvail().x;

    float off = (avail - size) * alignment;
    if (off > 0.0f)
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);

    return ImGui::Button(label);
}

void ImGuiUtility::AlignForWidth(float width, float alignment) {
    ImGuiStyle &style = ImGui::GetStyle();
    float avail = ImGui::GetContentRegionAvail().x;
    float off = (avail - width) * alignment;
    if (off > 0.0f)
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + off);
}

float ImGuiUtility::CalculateTextWidth(const char *text) {
    ImGuiStyle &style = ImGui::GetStyle();
    return ImGui::CalcTextSize(text).x + style.ItemSpacing.x;
}
