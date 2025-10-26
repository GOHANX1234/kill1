#include <android/log.h>
#include <unistd.h>
#include <thread>
#include <limits>
#include <KittyMemory/KittyMemory.h>
#include <KittyMemory/MemoryPatch.h>
#include <KittyMemory/KittyScanner.h>
#include <KittyMemory/KittyUtils.h>
#include "oxorany/oxorany.h"
#include <xdl.h>
#include <KittyUtils.h>
#include <KittyMemory.h>
#include <Il2Cpp.h>
#include <SubstrateHook.h>
#include <CydiaSubstrate.h>
#include "Xopun~hooks/gui.hpp"
#include "il2cpp.h"
#include "Xopun~tools/Land.hpp"
#include "imgui/imgui.h"
#include "imgui/stb_image.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include <Themes.h>
#include "Xopun~tools/Firewall.h"
#include "Xopun~tools/exptime.h"
#include "Xopun~tools/Chams.h"
#include "Xopun~tools/Land.h"
#include "Xopun~tools/CN.h"
#include "Xopun~tools/lundbda.h"
#include "Xopun~tools/fontch.h"
#include "Icon/OPPOSans-H.h"
#include "Xopun~Op/Icon.h"
#include "Xopun~Op/Iconcpp.h"
#include <fstream>
void (*OpenURL)(String *url);
#include "GHr_Ryuuka/Tools/Call_Tools.h"
using json = nlohmann::json;
time_t rng = 0;
std::string g_Token, g_Auth;
#include "LoginBYxopun.h"

#include "Fonts.h"
ImFont* poppins_mediumf = nullptr;
ImFont* poppins_medium_low = nullptr;


using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

#define ALPHA    ( ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder )
#define NO_ALPHA ( ImGuiColorEditFlags_NoTooltip    | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_Float | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_PickerHueBar | ImGuiColorEditFlags_NoBorder )

void HueText(const char* text, ImVec4 color)
{
    static auto start_time = std::chrono::high_resolution_clock::now();
    auto elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count() / 1000.0f; 
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 0.0f)); 
    for (int i = 0; i < strlen(text); i++)
    {
      ImGui::SameLine();
        float t = fmodf(elapsed_seconds + (float)i / (float)strlen(text), 0.65f); 
        ImVec4 currentColor = ImVec4(color.x * t, color.y * t, color.z * t, color.w); 
        ImGui::PushStyleColor(ImGuiCol_Text, currentColor); 
        ImGui::Text("%c", text[i]); 
        ImGui::PopStyleColor(); 
    }
    ImGui::PopStyleColor(); 
}
/*
*/
void hack();
void writeLog(const std::string& logMessage, const std::string& filename = "/storage/emulated/0/Android/data/com.dualspace.multispace.androidx/files/log.txt");


 


class MyModule : public zygisk::ModuleBase {
 public:
  void onLoad(Api *api, JNIEnv *env) override {
    this->api_ = api;
    this->env_ = env;
    genv = env;
   // gEnv = env;

  }

  void preAppSpecialize(AppSpecializeArgs *args) override {
    static constexpr const char *packages[] = {
        "com.dts.freefireth"
    };
    const char *process = env_->GetStringUTFChars(args->nice_name, nullptr);
    for (const auto *package: packages) {
      is_game_ = (strcmp(process, package) == 0);
      if (is_game_) {
        break;
      }
    }
    env_->ReleaseStringUTFChars(args->nice_name, process);
  }

  void postAppSpecialize(const AppSpecializeArgs *args) override {
    if (is_game_) {
       genv->GetJavaVM(&jvm);
     //  genv->GetJavaVM(&gJvm);
      std::thread{hack}.detach();
    }
  }

 private:
  Api *api_ = nullptr;
  JNIEnv *env_ = nullptr;
  bool is_game_ = false;
};


uintptr_t il2cpp_base = 0;
void *getRealAddr(ulong offset) {
    return reinterpret_cast<void*>(il2cpp_base + offset);
};

#include "imgui.h"
#include <cmath>

static ImVec4 g_MenuColor = ImVec4(200.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f, 1.0f);
static bool g_ColorPickerOpen = false;

ImU32 GetMenuColor(int alpha = 255) {
    return IM_COL32(
        (int)(g_MenuColor.x * 255.0f),
        (int)(g_MenuColor.y * 255.0f),
        (int)(g_MenuColor.z * 255.0f),
        alpha
    );
}

ImVec4 GetMenuColorVec4(float alpha = 1.0f) {
    return ImVec4(g_MenuColor.x, g_MenuColor.y, g_MenuColor.z, alpha);
}

void ApplyMenuTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;
    
    colors[ImGuiCol_TitleBg]          = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_TitleBgActive]    = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_TitleBgCollapsed] = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_Button]           = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_ButtonHovered]    = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_ButtonActive]     = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_Header]           = GetMenuColorVec4(0.78f);
    colors[ImGuiCol_HeaderHovered]    = GetMenuColorVec4(0.86f);
    colors[ImGuiCol_HeaderActive]     = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_SliderGrab]       = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_SliderGrabActive] = GetMenuColorVec4(0.86f);
    colors[ImGuiCol_CheckMark]        = GetMenuColorVec4(1.0f);
    colors[ImGuiCol_Border]           = GetMenuColorVec4(0.0f);
}

bool StyledCheckbox(const char* label, bool* v)
{
    ImGui::PushID(label);
    
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0.20f, 0.15f, 0.25f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0.25f, 0.15f, 0.30f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_CheckMark, GetMenuColorVec4(1.0f));
    
    bool changed = ImGui::Checkbox(label, v);
    
    ImGui::PopStyleColor(4);
    ImGui::PopID();
    
    return changed;
}

// --- Left Nav Button (tab button) - Icon Only Version ---
static bool LeftNavButton(const char* label, const char* icon, bool selected, ImVec2 size = ImVec2(84, 90)) {
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));

    ImU32 icon_bg_col = GetMenuColor(255);
    
    ImVec2 icon_rect_min(pos.x + 6, pos.y + 6);
    ImVec2 icon_rect_max(pos.x + size.x - 6, pos.y + size.y - 6);
    dl->AddRectFilled(icon_rect_min, icon_rect_max, icon_bg_col, 5.0f);
    
    ImFont* small_font = ImGui::GetIO().Fonts->Fonts[0];
    ImVec2 icon_size = small_font->CalcTextSizeA(20.0f, FLT_MAX, 0.0f, icon);
    ImVec2 icon_pos(pos.x + (size.x - icon_size.x) * 0.5f, pos.y + (size.y - icon_size.y) * 0.5f);
    
    dl->AddText(small_font, 20.0f, icon_pos, IM_COL32(255,255,255,255), icon);

    ImGui::InvisibleButton(label, size);
    bool clicked = ImGui::IsItemClicked();

    return clicked;
}

namespace Settings
{
static int Tab = 1;
}

#define ICON_FA_WINDOW_MINIMIZE "\xef\x8a\x96"

void SetupImgui() {
IMGUI_CHECKVERSION();
//InitTexture();
ImGui::CreateContext();
ImGui_ImplOpenGL3_Init("#version 300 es");

            ImGuiIO &io = ImGui::GetIO();
            
// 
ImGuiStyle& style = ImGui::GetStyle();
ImVec4* colors = style.Colors;

// ====== WINDOW COLORS - DARK THEME ======
colors[ImGuiCol_WindowBg]         = ImColor(0, 0, 0, 255);
colors[ImGuiCol_ChildBg]          = ImColor(0, 0, 0, 255);
colors[ImGuiCol_PopupBg]          = ImColor(0, 0, 0, 255);
colors[ImGuiCol_Border]           = ImVec4(0, 0, 0, 0);
colors[ImGuiCol_BorderShadow]     = ImVec4(0, 0, 0, 0);
colors[ImGuiCol_TitleBg]          = GetMenuColorVec4(1.0f);
colors[ImGuiCol_TitleBgActive]    = GetMenuColorVec4(1.0f);
colors[ImGuiCol_TitleBgCollapsed] = GetMenuColorVec4(1.0f);

// ====== BUTTON COLORS ======
colors[ImGuiCol_Button]           = GetMenuColorVec4(1.0f);
colors[ImGuiCol_ButtonHovered]    = GetMenuColorVec4(1.0f);
colors[ImGuiCol_ButtonActive]     = GetMenuColorVec4(1.0f);

// ====== TEXT COLORS ======
colors[ImGuiCol_Text]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
colors[ImGuiCol_TextDisabled]     = ImVec4(0.50f, 0.40f, 0.55f, 1.00f);

// ====== FRAME COLORS - DARK ======
colors[ImGuiCol_FrameBg]          = ImVec4(0.12f, 0.10f, 0.15f, 1.00f);
colors[ImGuiCol_FrameBgHovered]   = ImVec4(0.16f, 0.12f, 0.20f, 1.00f);
colors[ImGuiCol_FrameBgActive]    = ImVec4(0.20f, 0.15f, 0.25f, 1.00f);

// ====== TAB / HEADER ======
colors[ImGuiCol_Header]           = GetMenuColorVec4(0.78f);
colors[ImGuiCol_HeaderHovered]    = GetMenuColorVec4(0.86f);
colors[ImGuiCol_HeaderActive]     = GetMenuColorVec4(1.0f);

// ====== SLIDER / CHECKBOX ======
colors[ImGuiCol_SliderGrab]       = GetMenuColorVec4(1.0f);
colors[ImGuiCol_SliderGrabActive] = GetMenuColorVec4(0.86f);
colors[ImGuiCol_CheckMark]        = GetMenuColorVec4(1.0f);

// ====== BORDER & WINDOW SETTINGS ======
style.WindowBorderSize  = 0.0f;  // No borders
style.FrameBorderSize   = 0.0f;  // No borders
style.ChildBorderSize   = 0.0f;  // No borders
style.PopupBorderSize   = 0.0f;  // No borders

style.WindowRounding    = 12.0f;   //
style.FrameRounding     = 8.0f; //
style.GrabRounding      = 0.0f; //
style.ChildRounding     = 12.0f;        //

style.WindowPadding     = ImVec2(18.0f, 18.0f); //
style.FramePadding      = ImVec2(10.0f, 6.0f);  // 
style.ItemSpacing       = ImVec2(10.0f, 10.0f); // 
style.ItemInnerSpacing  = ImVec2(6.0f, 6.0f);   //

// ====== OPTIONAL FONT STYLE ======
style.WindowTitleAlign  = ImVec2(0.5f, 0.5f); //
style.DisplaySafeAreaPadding = ImVec2(0, 0);    //

            io.ConfigWindowsMoveFromTitleBarOnly = true;
            io.IniFilename = NULL;

            static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
            ImFontConfig icons_config;

            ImFontConfig CustomFont;
            CustomFont.FontDataOwnedByAtlas = false;

            icons_config.MergeMode = true;
            icons_config.PixelSnapH = true;
            icons_config.OversampleH = 2.5;
            icons_config.OversampleV = 2.5;
            
          io.Fonts->AddFontFromMemoryTTF(&PoppinsRegular, sizeof PoppinsRegular, 29, NULL, io.Fonts->GetGlyphRangesVietnamese());
                  io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);
                  io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 24.f, &CustomFont);
         // memset(&Config, 0, sizeof(sConfig));
//

//ImFontConfig CustomFont;
CustomFont.FontDataOwnedByAtlas = false;
//font_cfg.SizePixels = 22.0f;
static const ImWchar vietnamese_chars[] = {
0x0020, 0x00FF, // Basic Latin + Latin Supplement
0x0102, 0x0103, // Â, â
0x0110, 0x0111, // Đ, đ
0x0128, 0x0129, // Ĩ, ĩ
0x0168, 0x0169, // Ũ, ũ
0x01A0, 0x01A1, // Ơ, ơ
0x01AF, 0x01B0, // Ư, ư
0x1EA0, 0x1EF9, // Vietnamese specific characters
0 // null-terminated list
};

ApplyMenuTheme();
}


bool clearMousePos = true;
bool ImGuiOK = false;
bool initImGui = false;


void VerticalTab(const char* label, int tab_index, int* p_selected_tab) {
ImGuiStyle& style = ImGui::GetStyle();
ImVec4* colors = style.Colors;

// Push custom colors for the selected and unselected states
ImVec4 color = ImColor(0, 150, 255, 5);
ImVec4 colorActive = ImColor(0, 150, 255, 5);
ImVec4 colorHovered = ImColor(0, 150, 255, 5);

if (tab_index == *p_selected_tab) {
// This is the selected tab, make it blue like in the image
ImGui::PushStyleColor(ImGuiCol_Button, colorActive);
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, colorActive);
ImGui::PushStyleColor(ImGuiCol_ButtonActive, colorActive);
} else {
// Unselected tabs are dark
ImGui::PushStyleColor(ImGuiCol_Button, color);
ImGui::PushStyleColor(ImGuiCol_ButtonHovered, colorHovered);
ImGui::PushStyleColor(ImGuiCol_ButtonActive, colorActive);
}

if (ImGui::Button(label, ImVec2(200, 50))) { // Button size (width, height)
*p_selected_tab = tab_index;
}

if (tab_index == *p_selected_tab) {
ImDrawList* draw_list = ImGui::GetWindowDrawList();
const ImVec2 p_min = ImGui::GetItemRectMin();
const ImVec2 p_max = ImGui::GetItemRectMax();

ImU32 line_color = IM_COL32(50, 150, 255, 255);
float line_thickness = 8.0f;

draw_list->AddLine(
ImVec2(p_min.x, p_min.y), 
ImVec2(p_min.x, p_max.y), 
line_color, 
line_thickness
);
}

ImGui::PopStyleColor(3);
}

static int selected_tab = 0;
inline EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
inline EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    
        eglQuerySurface(dpy, surface, EGL_WIDTH, &g_GlWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &g_GlHeight);
    
    


    if (!g_IsSetup) {
        prevWidth = g_GlWidth;
        prevHeight = g_GlHeight;
        SetupImgui();
        
        g_IsSetup = true;
    }
    
 // Window background = black

    ImGuiIO &io = ImGui::GetIO();
        //Darkness();
        // Thiết lập màu chủ đề
        //ImVec4* colors = ImGui::GetStyle().Colors;


    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(g_GlWidth, g_GlHeight);
    ImGui::NewFrame();
        if (ImGuiOK) {
            int touchCount = (((int (*)())(Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Input"), OBFUSCATE("get_touchCount"))))());
        if (touchCount > 0) {
                UnityEngine_Touch_Fields touch = ((UnityEngine_Touch_Fields(*)(int))(Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Input"), OBFUSCATE("GetTouch"), 1)))(0);
                float reverseY = io.DisplaySize.y - touch.m_Position.fields.y;
                switch (touch.m_Phase) {
                case TouchPhase::Began:
                case TouchPhase::Stationary:
                        io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                        io.MouseDown[0] = true;
                        
                        break;
                case TouchPhase::Ended:
                case TouchPhase::Canceled:
                        io.MouseDown[0] = false;
                        clearMousePos = true;
                break; case TouchPhase::Moved:
                        io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                break; default:break;
                }
        }
        }
        
        DrawESP(g_GlWidth, g_GlHeight);
        
        ImDrawList*draw = ImGui::GetBackgroundDrawList();



    // Font Awesome icon defines
    #define ICON_FA_CROSSHAIRS "\xef\x81\x9b"
    #define ICON_FA_EYE "\xef\x81\xae"
    #define ICON_FA_FIRE "\xef\x81\xad"
    #define ICON_FA_USER_SECRET "\xef\x88\x9b"
    #define ICON_FA_TIMES "\xef\x80\x8d"
        
    static bool show_menu = true;
    
    if (show_menu) {
        ImGui::SetNextWindowSize(ImVec2(620, 410), ImGuiCond_Once);
        ImGui::Begin(OBFUSCATE("DEXXTER MOD APK V1"), &show_menu, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar);
        
        ImDrawList* dl = ImGui::GetWindowDrawList();
        ImVec2 pos = ImGui::GetWindowPos();
        ImVec2 size = ImGui::GetWindowSize();
        
        ImVec2 close_btn_pos = ImVec2(pos.x + size.x - 40, pos.y + 8);
        ImGui::SetCursorScreenPos(close_btn_pos);
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, GetMenuColorVec4(0.39f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, GetMenuColorVec4(0.71f));
        ImGui::PushStyleColor(ImGuiCol_Text, GetMenuColorVec4(1.0f));
        if (ImGui::Button(ICON_FA_TIMES, ImVec2(28, 28))) {
            show_menu = false;
        }
        ImGui::PopStyleColor(4);
        
        ImGui::SetCursorPos(ImVec2(8, 45));

        static int tab = 0;
        
        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 12.0f);

        ImGui::BeginChild("LeftTabs", ImVec2(96, 350), true, ImGuiWindowFlags_NoScrollbar);
        ImGui::SetCursorPosY(8);
        if (LeftNavButton("AIMBOT", ICON_FA_CROSSHAIRS, tab == 0)) tab = 0;
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 14);
        if (LeftNavButton("VISUAL", ICON_FA_EYE, tab == 1)) tab = 1;
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 14);
        if (LeftNavButton("BRUTAL", ICON_FA_FIRE, tab == 2)) tab = 2;
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 14);
        if (LeftNavButton("INFO", ICON_FA_USER_SECRET, tab == 3)) tab = 3;
        ImGui::EndChild();
        ImGui::PopStyleVar();

        ImGui::SameLine(0, 4);

        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 12.0f);

        ImGui::BeginChild("ContentChild", ImVec2(500, 350), true, ImGuiWindowFlags_NoScrollbar);
        
        ImVec2 content_pos = ImGui::GetCursorScreenPos();
        dl->AddLine(ImVec2(content_pos.x + 4, content_pos.y + 16), 
                    ImVec2(content_pos.x + 500, content_pos.y + 16), 
                    IM_COL32(255, 255, 255, 180), 1.0f);
        
        ImGui::SetCursorPosY(26);
        
        switch (tab) {
            case 0:
                StyledCheckbox(" ACTIVE FUNCTION", &Enable);
                ImGui::Spacing();
                StyledCheckbox(" AIMBOT", &Aimbot);
                ImGui::Spacing();
                ImGui::SliderFloat(("AIM FOV"), &Fov_Aim, 0.0f, 1000.0f, "%.0f°", ImGuiSliderFlags_AlwaysClamp | ImGuiSliderFlags_NoInput);
                ImGui::Spacing();
                if (ImGui::Button("JOIN TELEGRAM", ImVec2(250, 40))) 
                {
                    OpenURL(Il2CppString::Create("https://t.me/Gohan52"));
                }
                break;
            case 1:
                StyledCheckbox(" ESP LINE", &Config.ESP.Line);
                ImGui::Spacing();
                StyledCheckbox(" ESP BOX", &Config.ESP.Box);
                ImGui::Spacing();
                StyledCheckbox(" ESP HEALTH", &Config.ESP.Health);
                break;
            case 2:
                StyledCheckbox(" AIMKILL", &AimKill1);
                ImGui::Spacing();
                
                 StyledCheckbox(" TELEPORT 10M (RISK)", &Mass.Sucks);
                ImGui::Spacing();
                break;
            case 3:
                ImGui::TextColored(GetMenuColorVec4(1.0f), "DEXXTER MOD APK V1");
                ImGui::Spacing();
                ImGui::Text("Developed by @Gohan52");
                ImGui::Spacing();
                ImGui::TextWrapped("Premium mod menu with advanced features.");
                ImGui::Spacing();
                ImGui::Spacing();
                
                ImGui::Separator();
                ImGui::Spacing();
                
                ImGui::TextColored(GetMenuColorVec4(1.0f), "MENU COLOUR");
                ImGui::Spacing();
                
                ImDrawList* draw_list = ImGui::GetWindowDrawList();
                ImVec2 preview_pos = ImGui::GetCursorScreenPos();
                ImVec2 preview_size(35, 35);
                
                draw_list->AddRectFilled(preview_pos, 
                    ImVec2(preview_pos.x + preview_size.x, preview_pos.y + preview_size.y), 
                    GetMenuColor(255), 5.0f);
                draw_list->AddRect(preview_pos, 
                    ImVec2(preview_pos.x + preview_size.x, preview_pos.y + preview_size.y), 
                    IM_COL32(255, 255, 255, 150), 5.0f, 0, 2.0f);
                
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 45);
                
                ImGui::PushStyleColor(ImGuiCol_Button, GetMenuColorVec4(1.0f));
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, GetMenuColorVec4(0.8f));
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, GetMenuColorVec4(0.9f));
                
                if (ImGui::Button("Pick Color", ImVec2(120, 35))) {
                    g_ColorPickerOpen = !g_ColorPickerOpen;
                }
                ImGui::PopStyleColor(3);
                
                if (g_ColorPickerOpen) {
                    ImGui::Spacing();
                    ImGui::SetNextItemWidth(300);
                    if (ImGui::ColorPicker4("##MenuColorPicker", (float*)&g_MenuColor, 
                        ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview | 
                        ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_PickerHueWheel)) {
                        ApplyMenuTheme();
                    }
                    
                    ImGui::Spacing();
                    if (ImGui::Button("Close", ImVec2(120, 30))) {
                        g_ColorPickerOpen = false;
                    }
                    
                    if (ImGui::IsMouseClicked(0)) {
                        ImVec2 mouse_pos = ImGui::GetMousePos();
                        ImVec2 picker_min = ImGui::GetItemRectMin();
                        ImVec2 picker_max = ImGui::GetItemRectMax();
                        
                        if (mouse_pos.x < content_pos.x || mouse_pos.x > content_pos.x + 500 ||
                            mouse_pos.y < content_pos.y || mouse_pos.y > content_pos.y + 350) {
                            if (!ImGui::IsItemHovered() && !ImGui::IsAnyItemHovered()) {
                                g_ColorPickerOpen = false;
                            }
                        }
                    }
                }
                
                ImGui::Spacing();
                ImGui::Text("Tap 'Pick Color' to customize theme!");
                break;
        }

        ImGui::EndChild();
        ImGui::PopStyleVar();
        
        ImGui::End();
    }
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        return old_eglSwapBuffers(dpy, surface);
}
//}
typedef unsigned long DWORD;
//static uintptr_t libBase;

uintptr_t string2Offset(const char *c) {
    int base = 16;
    // See if this function catches all possibilities.
    // If it doesn't, the function would have to be amended
    // whenever you add a combination of architecture and
    // compiler that is not yet addressed.
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}


inline void hack_injec();
inline void StartGUI() {
    void *ptr_eglSwapBuffer = DobbySymbolResolver("/system/lib/libEGL.so", "eglSwapBuffers");
    if (NULL != ptr_eglSwapBuffer) {
        DobbyHook((void *)ptr_eglSwapBuffer, (void*)hook_eglSwapBuffers, (void**)&old_eglSwapBuffers);
            LOGD("Gui Started");
                        hack_injec();
        }
    }

bool libLoaded = false;

DWORD findLibrary(const char *library) {
    char filename[0xFF] = {0},
            buffer[1024] = {0};
    FILE *fp = NULL;
    DWORD address = 0;

    sprintf(filename, OBFUSCATE("/proc/self/maps"));

    fp = fopen(filename, OBFUSCATE("rt"));
    if (fp == NULL) {
        perror(OBFUSCATE("fopen"));
        goto done;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, library)) {
            address = (DWORD) strtoul(buffer, NULL, 16);
            goto done;
        }
    }

    done:

    if (fp) {
        fclose(fp);
    }

    return address;
}

DWORD getAbsoluteAddress(const char *libraryName, DWORD relativeAddr) {
    libBase = findLibrary(libraryName);
    if (libBase == 0)
        return 0;
    return (reinterpret_cast<DWORD>(libBase + relativeAddr));
}
ProcMap unityMap, anogsMap, il2cppMap;
using KittyScanner::RegisterNativeFn;



    
    
void hack() {
     LOGD("Inject Ok");
    //std::thread thread_hack(hack_thread, getpid());
    //thread_hack.detach();
    
}
uintptr_t get_symbol_addr_in_pid(pid_t pid, const char* libname, uintptr_t offset_in_lib) {
    char maps_path[64];
    snprintf(maps_path, sizeof(maps_path), "/proc/%d/maps", pid);

    FILE* fp = fopen(maps_path, "r");
    if (!fp) return 0;

    char line[512];
    uintptr_t base = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, libname)) {
            sscanf(line, "%lx-%*lx", &base);
            break;
        }
    }
    fclose(fp);

    if (base == 0) return 0;
    return base + offset_in_lib;
}

pid_t get_pid_by_name(const char* process_name) {
    DIR* proc_dir = opendir("/proc");
    if (!proc_dir) return -1;

    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type != DT_DIR) continue;

        pid_t pid = atoi(entry->d_name);
        if (pid <= 0) continue;

        char cmdline_path[256];
        snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", pid);

        FILE* fp = fopen(cmdline_path, "r");
        if (!fp) continue;

        char cmdline[256];
        fgets(cmdline, sizeof(cmdline), fp);
        fclose(fp);

        if (strstr(cmdline, process_name)) {
            closedir(proc_dir);
            return pid;
        }
    }

    closedir(proc_dir);
    return -1;
}

void writeLog(const std::string& logMessage, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app); // Mở file ở chế độ append (thêm)
    if (outFile.is_open()) {
        outFile << logMessage << std::endl;
        outFile.close();
    } else {
        std::cerr << "Không thể mở file log: " << filename << std::endl;
    }
}

bool is_current_process(const char* target_name) {
    char cmdline_path[64];
    snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", getpid());

    FILE* fp = fopen(cmdline_path, "r");
    if (!fp) return false;

    char cmdline[256] = {0};
    fgets(cmdline, sizeof(cmdline), fp);
    fclose(fp);

    return strcmp(cmdline, target_name) == 0;
}




void hack_injec() {
        while (!unityMap.isValid()) {
        unityMap = KittyMemory::getLibraryBaseMap("libunity.so");
                anogsMap = KittyMemory::getLibraryBaseMap("libanogs.so");
                il2cppMap = KittyMemory::getLibraryBaseMap("libil2cpp.so");
                
        sleep(6);
        }
    
 sleep(5);
    Il2CppAttach();
    
    if (mlovinit()) {
        setShader("_AlphaMask"); //Varies according to game
        LogShaders();
        Wallhack();
    }

A64HookFunction(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("UpdateBehavior"), 2), (void *) _LateUpdate, (void **) &LateUpdate);
        OpenURL = (void (*)(String *))Il2CppGetMethodOffset("UnityEngine.CoreModule.dll","UnityEngine","Application","OpenURL",1);

    ImGuiOK = true;
    
}


void hack_thread(pid_t pid) {
        
        StartGUI();
        while(pid == -1){pid = get_pid_by_name("com.dts.freefireth");} 
        remote_inject(pid);
        writeLog(to_string(pid));
    
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void * reserved) {
jvm = vm;
JNIEnv *env;
vm->GetEnv((void **) &env, JNI_VERSION_1_6); 
return JNI_VERSION_1_6;
}

__attribute__((constructor))
void lib_main()
{
    std::thread thread_hack(hack_thread, get_pid_by_name("com.dts.freefireth"));
    thread_hack.detach();
}
//REGISTER_ZYGISK_MODULE(MyModule)

