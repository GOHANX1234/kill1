
#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <Il2Cpp.h>
#include <Tools.h>
#include <Vector3.hpp>
#include <Color.h>

#include "obfuscate.h"
#include "Unity/unity.h"
#include "Class.h"
#include "Rect.h"
#include "Bools.h"
#include <math.h>
#include <stdio.h>

#include "XopunAimkill.h"
inline static int g_GlHeight, g_GlWidth;
typedef char PACKAGENAME;
//#include "MemoryPatch.h"
// Khai Báo

#define ICON_FA_TELEGRAM "\xef\x8b\x86" // U+f2c6
#define ICON_FA_SHIELD "\xef\x84\xb2" // U+f132 - Shield/Warrior icon 

float density = -1;

extern ImVec4 g_EspColor;
struct cfg {
    bool aimbot;
    int aim_type = 0;
    int aim_target = 1;
    struct _esp {
        bool Box = false;
        bool Box3D = false;
        bool Line = false;
                bool Info = false;
                //bool Egline = false;
        bool Health = false;
        bool Distance = false;
        bool IsName = false;
        bool Path = false;
        bool Esp360 = false;
        bool Target = false;
    }ESP;
}inline Config;
bool AimWhen3 = false;
bool AimWhen2 = true;
bool box = false;
//bool totalEnemies = true;
bool AimWhen1 = false;
//boo prince.Egline = false;
bool showbox1 = false;
bool showline1 = false;
bool camxa = false;
//bool EspGranada = false;
//EspGrenade = !EspGrenade;
bool showline2 = false;
bool AimSilent = false;
bool camcao = false;
bool showline = false;
bool speedrun = false;
bool Firewall = true;
bool health = false;
bool Headshot = false;
bool AimNewF = true;
//int showline = 0;
struct MassKill {
float Sucks1 = 10.0f;
bool Sucks = false;
float FrontOffset = 0.5f;
}Mass;

bool ActiveFeature = true;

float AimFov2 = 360.0f;

bool AimVisible2 = true;
float DistanceTele = 0;




const char* line[] = {OBFUSCATE("Esp Line 1"),OBFUSCATE("Esp Line 2"),OBFUSCATE("Esp Line 3")};

int showbox = 1;
//MemoryPatch  Resetguest,DouleGun,nightmod,WallHack2;

//const char* box[] = {OBFUSCATE("Esp Box"),OBFUSCATE("Esp Box 3D")};

struct sColor {
        float circle[4] = {0 / 255.0f, 255 / 255.0f, 0 / 255.0f, 255 / 255.0f};

                float box[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float line1[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float box1[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float box3d1[4] = {255 / 255.0f, 255 / 255.0f, 255 / 255.0f, 255 / 255.0f};
        float info1[4] = {0 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};

        float line2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
        float box2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
        float box3d2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
        float info2[4] = {255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f};
};
sColor Color;
bool Reset = false;



bool isOutsideScreen(ImVec2 pos, ImVec2 screen) {
    if (pos.y < 0) {
        return true;
    }
    if (pos.x > screen.x) {
        return true;
    }
    if (pos.y > screen.y) {
        return true;
    }
    return pos.x < 0;
}

ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset) {
    int x = (int) Pos.x;
    int y = (int) Pos.y;
    
    if (Pos.y < 0) {
        y = -offset;
    }
    
    if (Pos.x > screen.x) {
        x = (int) screen.x + offset;
    }
    
    if (Pos.y > screen.y) {
        y = (int) screen.y + offset;
    }
    
    if (Pos.x < 0) {
        x = -offset;
    }
    return ImVec2(x, y);
}

static float tm = 127 / 255.f;

void(*Set_Aim)(void* _this);
void _Set_Aim(void* _this) {
    return;
    return Set_Aim(_this);
}

// BYPASS
bool(*Bypass)(void* bypass); 
bool _Bypass(void* bypass) { 
    return false;
}

bool(*FixGame)(void* _this);
bool _FixGame(void* _this) {
    if (_this != NULL) {
        return true;
    }
}

bool(*BypassESP)(void* _this);
bool _BypassESP(void* _this) {
    return true;
}

bool(*Bypass2)(void* _this);
bool _Bypass2(void* _this) {
    return true;
}

void DrawCircleHealth(ImVec2 position, int health, int max_health, float radius) {
    float a_max = ((3.14159265359f * 2.0f));
    ImU32 healthColor = IM_COL32(45, 180, 45, 255);
    if (health <= (max_health * 0.6)) {
        healthColor = IM_COL32(180, 180, 45, 255);
    }
    if (health < (max_health * 0.3)) {
        healthColor = IM_COL32(180, 45, 45, 255);
    }
    ImGui::GetForegroundDrawList()->PathArcTo(position, radius, (-(a_max / 4.0f)) + (a_max / max_health) * (max_health - health), a_max - (a_max / 4.0f));
    ImGui::GetForegroundDrawList()->PathStroke(healthColor, ImDrawFlags_None, 4);
}

void drawText2(int x, int y, long color, const char *str, float size) {
    ImGui::GetBackgroundDrawList()->AddText(NULL, size, ImVec2(x, y), color, str);
}

void DrawRectFilled(int x, int y, int w, int h, ImColor color) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}

void DrawRectFilledHealth(int x, int y, int w, int h, ImVec4 color) {
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(color), 0, 0);
}

void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, int T) {
    ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(x1, y1), ImVec2(x2, y2), ImVec2(x3, y3), color);
}

void DrawHealths(Rect box, float entityHealth, float maxHealth, int TeamID, const char* name, long color) {
    float x = box.x - (140 - box.w) / 2;
    float y = box.y;
    char dis[20];
    // sprintf(dis, "%0.fM", d);

    char TeamText[20];
    sprintf(TeamText, "%d", (int)TeamID);
    ImVec4 HPColor = ImVec4{1, 1, 0, 127 / 255.f}; // Màu mặc định cho máu

    if (entityHealth < maxHealth) {
        float healthPercentage = entityHealth / maxHealth;

        if (healthPercentage < 0.3f) {
            HPColor = ImVec4{0.5f, 0.0f, 0.0f, 127 / 255.f}; // Màu đỏ cho máu thấp
        } else if (healthPercentage < 0.6f) {
            HPColor = ImVec4{1, 0, 0, 127 / 255.f}; // Màu cam cho máu trung bình
        }
    }

    tm = 100.f / 255.f;
    DrawRectFilled(x - strlen(name), y - 41, 120 + strlen(name) * 2, 20, color); // Đám mây nền cho tên người chơi
    tm = 255.f / 255.f;
    DrawRectFilled(x - strlen(name), box.y - 41, 25, 20, color);
    if (strlen(TeamText) < 2) {
        drawText2(x + 6 - strlen(name), box.y - 42, ImColor(255,255,255), TeamText, 18.943);
    } else {
        drawText2(x - strlen(name), box.y - 42, ImColor(255,255,255), TeamText, 18.943);
    }
    drawText2(x + 28 - strlen(name), y - 43, ImColor(255,255,255), name, 18.943);
    float maxWidth = 120; // Độ dài tối đa của thanh máu
    float healthBarWidth = entityHealth * maxWidth / maxHealth; // Độ dài thanh máu dựa trên tỷ lệ máu hiện tại và máu tối đa
    DrawRectFilledHealth(x - maxWidth / 2, y - 18, healthBarWidth, 8, HPColor);// cập nhật vị trí và kích thước của thanh máu
    drawText2(x + 125 + strlen(name), y - 43, ImColor(255,255,255), dis,18.943);
    DrawTriangle(box.x + box.w / 2 - 10, y - 8, box.x + box.w / 2 + 15 - 10, y - 8, box.x + box.w / 2 - 2, y, ImColor(255,255,255), 1);
}

static float SetFieldOfView = 0, GetFieldOfView = 0;



float (*get_deltaTime)();
float smoothSpeedAIM = 5; 
void *MyPlayer = NULL;
bool Drone;

const float RADAR_SIZE = 200.0f; // kích thước của radar
const ImVec2 RADAR_CENTER(100.0f, 100.0f); // tọa độ trung tâm của radar

float x,y;
float enemy1 = 2.0f;

inline void DrawAIMBOT(float screenWidth, float screenHeight) { 
}

void DroneView() {
    if (GetFieldOfView == 0) {
        GetFieldOfView = get_fieldOfView();
    }
    if (SetFieldOfView > 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView + SetFieldOfView);
    }
    if (SetFieldOfView == 0 && GetFieldOfView != 0) {
        set_fieldOfView((float)GetFieldOfView);
    }
}

Quaternion GetRotationToTheLocation(Vector3 Target, float Height, Vector3 MyEnemy) {
return Quaternion::LookRotation((Target + Vector3(0, Height, 0)) - MyEnemy, Vector3(0, 1, 0));
}

bool isVisible(void *enemy)  {
    if(enemy != NULL)  {
         void *hitObj = NULL;
         auto Camera = Transform_GetPosition(Component_GetTransform(Camera_main()));
         auto Target = Transform_GetPosition(Component_GetTransform(Player_GetHeadCollider(enemy)));
         return !Physics_Raycast(Camera, Target, 12, &hitObj);
    }
    return false;
}
bool Visible_Check(void *closestEnemy) {
    void *Object = static_cast<void *>(nullptr);
    Vector3 Camera = Transform_INTERNAL_GetPosition(Component_GetTransform(Camera_main()));
    Vector3 Collider = Transform_INTERNAL_GetPosition(Component_GetTransform(GetHeadCollider(closestEnemy)));
    if (!Cristiano_RayVery(Camera, Collider, 12, &Object)) {
        return true;
    } else {
        return false;
    }
}
void *GetClosestEnemy() {
    float shortestDistance = 9999;
    void* closestEnemy = NULL;   
     
    void* get_MatchGame = Curent_Match();
    void* LocalPlayer = GetLocalPlayer(get_MatchGame);

    if (LocalPlayer != NULL && get_MatchGame != NULL && Enable && get_MatchGame) {
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t*, void **> **)((long)get_MatchGame + ListPlayer);
        
        for (int u = 0; u < players->getNumValues(); u++) {
            void* Player = players->getValues()[u]; 
            if (Player != NULL && !get_isLocalTeam(Player) && !get_IsDieing(Player) && get_isVisible(Player) && get_MaxHP(Player)) {    
                Vector3 PlayerPos = getPosition(Player);
                Vector3 LocalPlayerPos = getPosition(LocalPlayer);
                Vector3 pos2 = WorldToScreenPoint(Camera_main(), PlayerPos);
                bool isFov1 = isFov(Vector3(pos2.x, pos2.y), Vector3(g_GlWidth / 2, g_GlHeight / 2), Fov_Aim);
            
                
                
                
                float distance = Vector3::Distance(LocalPlayerPos, PlayerPos);
                if (distance < 1000) {
                    Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
                    float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0;             
            
                    if (angle <= Fov_Aim && isFov1 && angle < shortestDistance) {
                     if(isVisible(Player)) {
                        shortestDistance = angle;
                        closestEnemy = Player;
                    }
                   }
                }
            }
        }
    }
    return closestEnemy;
}
void *EnemyVisible(void *match) {
    if(!match || !ActiveFeature) {
        return nullptr;
    }
    float shortestDistance = 99999.0f;
    float maxAngle=AimFov2;
    void* closestEnemy = NULL;
    void* LocalPlayer = GetLocalPlayer(match);
    if(LocalPlayer != nullptr) {
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t*, void **> **)((long)match + offset_Dictionary);        
        for(int u = 0; u < players->getNumValues(); u++) {
            void* Player = players->getValues()[u];
            if(Player != NULL && !get_isLocalTeam(Player) && !get_IsDieing(Player) && get_isVisible(Player) && get_MaxHP(Player)) {
               Vector3 PlayerPos = GetHeadPosition(Player);
               Vector3 LocalPlayerPos = GetHeadPosition(LocalPlayer);              
               Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
               float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0;
               if (!get_God(Player)) {
                if (AimVisible2) {
                    if (Visible_Check(Player)) {
                       if(angle <= maxAngle) {
                        if(angle < shortestDistance) {
                            shortestDistance = angle;
                            closestEnemy = Player;
                            }
                        }
                    }
                }else if (!AimVisible2) {
                      if(angle <= maxAngle) {
                       if(angle < shortestDistance) {
                            shortestDistance = angle;
                            closestEnemy = Player;
                            }
                      }
                 }
               }
             }
         }
     }
    return closestEnemy;
}

void *GetClosestEnemy2(void *match) {
    if(!match || !ActiveFeature) {
        return nullptr;
    }
    float shortestDistance = 99999.0f;
    float maxAngle=AimFov2;
    void* closestEnemy = NULL;
    void* LocalPlayer = GetLocalPlayer(match);
    if(LocalPlayer != nullptr) {
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t*, void **> **)((long)match + offset_Dictionary);        
        for(int u = 0; u < players->getNumValues(); u++) {
            void* Player = players->getValues()[u];
            if(Player != NULL && !get_isLocalTeam(Player) && !get_IsDieing(Player) && get_isVisible(Player) && get_MaxHP(Player)) {
               Vector3 PlayerPos = GetHeadPosition(Player);
               Vector3 LocalPlayerPos = GetHeadPosition(LocalPlayer);              
               Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
               float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0;
               if (!get_God(Player)) {
                       if(angle <= maxAngle) {
                        if(angle < shortestDistance) {
                            shortestDistance = angle;
                            closestEnemy = Player;
                            }
                        }
                    }
                }
           }
       }
    return closestEnemy;
}
void Aimbot2(void *LocalPlayer, void *Player) {
void* CurrentMatch = Curent_Match();
  if(CurrentMatch != nullptr) {
     void* LocalPlayer = GetLocalPlayer(CurrentMatch);
         if(LocalPlayer != nullptr) {
         void *WeaponHand = GetWeaponOnHand1(Current_Local_Player());
         void *camera = Camera_main();

            void* closestEnemy = GetClosestEnemy2(CurrentMatch);
            if(closestEnemy != nullptr) {
            Vector3 LocalPlayerPos2 = GetAttackableCenterWS(LocalPlayer);
            Vector3 LocalPlayerPos = GetHeadPosition(LocalPlayer);
            Vector3 PlayerLocation = CameraMain(LocalPlayer);
            Vector3 PlayerHeadPos = GetHeadPosition(closestEnemy);
             Vector3 PositionRoot = WorldToScreenPoint(camera, Transform_INTERNAL_GetPosition(Component_GetTransform(closestEnemy)));
             Vector3 PositionHead = WorldToScreenPoint(camera, Transform_INTERNAL_GetPosition(Component_GetTransform(closestEnemy)) + Vector3(0, 1.9f, 0));
             float distance = Vector3::Distance(PlayerHeadPos, LocalPlayerPos);
             DistanceTele = distance;
              auto *Player = EnemyVisible(CurrentMatch);
                if (Player != nullptr && EnemyVisible != LocalPlayer) {
                
           if (Aim == 0) {
             SetDamage = 1;
           }else if (Aim == 1) {
             SetDamage = 0;
           }
           
           
           
          
          
           
    
          
      
      }
      }}}
      

}

struct HitObjectInfo {
    void *klass;
    void *monitor;
    bool m_IsInPool;
    void *HitObject;
    void *HitCollider;
    Vector3 HitLocation;
    Vector3 HitNormal;
    Vector3 RayDir;
    Vector3 StartPosition;
    int32_t Damage;
    float Distance;
    int32_t ActorLayer;
    int32_t HitGroup;
    void *HitPhysicMaterial;
    bool IgnoreHappens;
    bool ViewBlocked;
    struct Vector3 OrigStartPosition;
    uint8_t SpecialHitType;
    uint32_t SpecialHitLevelObjID;
};
struct PlayerID_MKFEKBKJCKE_o;




int (*orig_PlayerNetwork_TakeDamage)(void *ClosestEnemy, int baseDamage, PlayerID damager, DamageInfo2_o *damageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> checkParams, void *damagerWeaponDynamicInfo, int damagerVehicleID);
int hook_PlayerNetwork_TakeDamage(void *ClosestEnemy, int baseDamage, PlayerID damager, DamageInfo2_o *damageInfo, int weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> checkParams, void *damagerWeaponDynamicInfo, int damagerVehicleID){
   //  DamageInfoHook = damageInfo;
     void* CurrentMatch = Curent_Match();
     void* LocalPlayer = GetLocalPlayer(CurrentMatch);
       firePos = GetHeadPosition(LocalPlayer);
       hitPos = GetHeadPosition(ClosestEnemy);
   if (ClosestEnemy != NULL && Headshot){
   if (damageInfo != NULL) {
     *(int *)((long) damageInfo + offset_BodyPart) = 1;
   }
  }
  return orig_PlayerNetwork_TakeDamage(ClosestEnemy, baseDamage, damager, damageInfo, weaponDataID, firePos, hitPos, checkParams, damagerWeaponDynamicInfo, damagerVehicleID);
}




int (*old_BLAGCMCGEJG1)(void *, HitObjectInfo *);
int BLAGCMCGEJG1(void *ist, HitObjectInfo *HitObject){
 if (SilentAim) {
  if (HitObject != nullptr){
    void *current_match = Curent_Match();
      if (current_match != NULL){
       void* local_player = GetLocalPlayer(current_match);
        if (local_player != NULL){
         void* WeaponHand = GetWeaponOnHand1(local_player);
         auto *ClosestEnemy = EnemyVisible(current_match);
          if (ClosestEnemy != nullptr){
            if (isEnemyInRangeWeapon(local_player, ClosestEnemy, WeaponHand)) {
            Vector3 EnemyLocation;
             if (SetDamage == 1) {
               EnemyLocation = GetHeadPosition(ClosestEnemy);
               }else if (SetDamage == 0){
               EnemyLocation = GetHipPosition(ClosestEnemy);}
               Vector3 PlayerLocation = CameraMain(local_player);
               HitObject->HitObject = get_gameObject(GetHeadCollider(ClosestEnemy));
               HitObject->HitCollider = GetHeadCollider(ClosestEnemy);
               HitObject->HitLocation = EnemyLocation;
               HitObject->HitNormal = EnemyLocation;
               HitObject->RayDir = Vector3::Normalized(EnemyLocation - PlayerLocation);
               HitObject->StartPosition = PlayerLocation;
               HitObject->OrigStartPosition = PlayerLocation;
               HitObject->SpecialHitType = 0;
               HitObject->HitGroup = 1;
               HitObject->IgnoreHappens = false;
               HitObject->ViewBlocked = false;
                    }
                 }
              }
           }
        }
     }
 return old_BLAGCMCGEJG1(ist, HitObject);
}











int tS1,tS2,tS3;


void _DarkUpdateX(void *player) {
  if (player != nullptr) {
      void *current_match = Curent_Match();
        if (current_match != NULL) {
          auto *PlayerS = EnemyVisible(current_match);
           void *local_player = Current_Local_Player();              
            if (local_player == NULL) {
                local_player = GetLocalPlayerOrObServer();
            }
            if (local_player != NULL) {
                void *fakeCamPlayer = get_MyFollowCamera(local_player);
                void *fakeCamEnemy = get_MyFollowCamera(player);
                if (fakeCamPlayer != NULL && fakeCamEnemy != NULL) {
                    void *fakeCamPlayerTF = Component_GetTransform(fakeCamPlayer);
                    void *fakeCamEnemyTF = Component_GetTransform(player);
                    if (fakeCamPlayerTF != NULL && fakeCamEnemyTF != NULL){
                        Vector3 fakeCamPlayerPos = Transform_INTERNAL_GetPosition(fakeCamPlayerTF);
                        Vector3 fakeCamEnemyPos = Transform_INTERNAL_GetPosition(fakeCamEnemyTF);
                        float distance = Vector3::Distance(fakeCamPlayerPos, fakeCamEnemyPos);
                        if (player != local_player){
                            if (distance > 0.1f) {
                                bool isSameTeam = get_isLocalTeam(player);
                                bool isVisible = get_isVisible(player);
                                bool isDieing = get_IsDieing(player);
                                if (!isSameTeam && isVisible && !isDieing) {
                                    if (ActiveFeature) {
                                Aimbot2(local_player, player);
                                  }
                               }
                             }                           
                         }
                    }
                 }
              }
           }
        }
}

void (*LateUpdate)(void *Player, void *param);
void _LateUpdate(void *Player, void *param){
        
int totalEnemies = 0; 
                
if (Player != NULL) {

if (Aimbot) {


void* CurrentMatch = Curent_Match();
void* closestEnemy = GetClosestEnemy();
void* LocalPlayer = GetLocalPlayer(CurrentMatch);

if (closestEnemy != NULL && LocalPlayer != NULL && CurrentMatch != NULL) {
    Vector3 EnemyLocation = GetHeadPosition(closestEnemy);
    Vector3 PlayerLocation = CameraMain(LocalPlayer);
    Quaternion PlayerLook = GetRotationToTheLocation(EnemyLocation, 0.1f, PlayerLocation);
    bool IsScopeOn = get_IsSighting(LocalPlayer);
    bool IsFiring = get_IsFiring(LocalPlayer);    
  
    if (AimWhen1) {
        set_aim(LocalPlayer, PlayerLook);
    }
    else if (AimWhen2 && IsFiring) {
        set_aim(LocalPlayer, PlayerLook);
    }
    else if (AimWhen3 && IsScopeOn) {
        set_aim(LocalPlayer, PlayerLook);
    }
    
    
    
    
    void *WeaponHand = GetWeaponOnHand1(Current_Local_Player());
         

           if (WeaponHand) {
            

               
               
               if (AimKill1) {
         if (damageCooldown <= 0) {
              StartTakeDamage(closestEnemy);
              StartonFiring(LocalPlayer, WeaponHand);
             damageCooldown = DamageDelay;
                } else {
            damageCooldown--;
            }
          }
          
           }
           
    
    
    
  }
  }
  }
  LateUpdate(Player, param);
}
void (*orig_mrSilentAim)(void *, float, float);
void hook_mrAimSilent(void *_this, float a1, float a2) {
if (_this != nullptr) {
if(Enable) {
if (AimSilent) {
void *CurrentMatch = Curent_Match();
if (CurrentMatch != NULL) {
void* LocalPlayer = GetLocalPlayer(CurrentMatch);
if (LocalPlayer != NULL)  {
bool visible = isVisible(LocalPlayer);
if (visible) {
if (get_IsFiring(GetLocalPlayer(CurrentMatch))) {
return;
} else {
orig_mrSilentAim(_this, a1, a2);
}
}
}
}
}
}
orig_mrSilentAim(_this, a1, a2);
}
}
        
inline void DrawESP(float screenWidth, float screenHeight) {
    ImDrawList* draw = ImGui::GetBackgroundDrawList();
        
    if (!draw) return;

    int totalEnemies = 0;

        if (Enable) {
        void* current_Match = Curent_Match();
        void* local_player = GetLocalPlayer(current_Match);

        if (local_player && current_Match) {
            auto* players = *(monoDictionary<uint8_t*, void**>**)((long)current_Match + ListPlayer);
            void* camera = Camera_main();

            if (players && camera) {
                for (int u = 0; u < players->getNumValues(); u++) {
                    void* closestEnemy = players->getValues()[u];
                    if (closestEnemy != local_player && closestEnemy && get_isVisible(closestEnemy) && !get_isLocalTeam(closestEnemy)) {
                        Vector3 Toepos = getPosition(closestEnemy);
                        Vector3 Toeposi = WorldToScreenPoint(camera, Toepos);
                        if (Toeposi.z < 1) continue;

                        Vector3 HeadPos = getPosition(closestEnemy) + Vector3(0, 1.9f, 0);
                        Vector3 HeadPosition = WorldToScreenPoint(camera, HeadPos);
                        if (HeadPosition.z < 1) continue;
                        
                        totalEnemies++;

                        

                        float distance = Vector3::Distance(getPosition(local_player), Toepos);
                        float Height = abs(HeadPosition.y - Toeposi.y) * (1.2 / 1.1);
                        float Width = Height * 0.50f;
                        Rect rect = Rect(HeadPosition.x - Width / 2.f, screenHeight - HeadPosition.y, Width, Height);
if (Mass.Sucks) {
    if (closestEnemy != NULL && local_player != NULL && closestEnemy != local_player && !get_IsDieing(closestEnemy)) {
        void* playerTransform = Component_GetTransform(local_player);
        void* enemyTransform  = Component_GetTransform(closestEnemy);

        if (playerTransform != NULL && enemyTransform != NULL) {
            Vector3 LocalPlayerPos = Transform_GetPosition(playerTransform);
            Vector3 EnemyPos       = Transform_GetPosition(enemyTransform);

            float distance = Vector3::Distance(LocalPlayerPos, EnemyPos);

            if (distance <= Mass.Sucks1) {
                Vector3 forward = GetForward(playerTransform);
                Vector3 newPos  = LocalPlayerPos + (forward * Mass.FrontOffset);

                // Optional: Validate newPos sanity
                if (isfinite(newPos.x) && isfinite(newPos.y) && isfinite(newPos.z)) {
                    Transform_INTERNAL_SetPosition(enemyTransform, Vvector3(newPos.x, newPos.y, newPos.z));
                }
            }
        }
    }
}
                        if (Config.ESP.Line) {
                         if(get_IsDieing(closestEnemy)) {
                            draw->AddLine(ImVec2(screenWidth / 2, 80), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), ImColor(255, 0, 0), 1.7);
                          } else {
                            draw->AddLine(ImVec2(screenWidth / 2, 80), ImVec2(rect.x + rect.w / 2, rect.y + rect.h / 35), ImColor((int)(g_EspColor.x * 255), (int)(g_EspColor.y * 255), (int)(g_EspColor.z * 255)), 1.7);
                        }
                        
                        }

      
     if (Config.ESP.Box) {
    int x = rect.x;
    int y = rect.y;
    int _width = rect.w;
    int _height = rect.h;

    if (get_IsDieing(closestEnemy)) {
        // Keep original red box for dying enemies
        draw->AddRect(
            ImVec2(x, y),
            ImVec2(x + _width, y + _height),
            ImColor(255, 0, 0),
            visual_esp_box,
            0,
            visual_esp_boxth
        );
    } else {
        // Full box for alive enemies with configurable color
        ImColor color = ImColor((int)(g_EspColor.x * 255), (int)(g_EspColor.y * 255), (int)(g_EspColor.z * 255));
        float thickness = visual_esp_boxth;

        draw->AddRect(
            ImVec2(x, y),
            ImVec2(x + _width, y + _height),
            color,
            visual_esp_box,
            0,
            thickness
        );
    }

    // Health Bar (keep your original logic for dying state)
    int xx = rect.x + rect.w + 2;
    int yy = rect.y;

    if (get_IsDieing(closestEnemy)) {
        if (Config.ESP.Health) {
            draw->AddRectFilled(ImVec2(xx, yy), ImVec2(xx + 5, yy + rect.h), ImColor(0, 0, 0, 255));
            draw->AddRectFilled(ImVec2(xx + 1, yy + rect.h - (rect.h * ((float)GetHp(closestEnemy) / get_MaxHP(closestEnemy)))), ImVec2(xx + 4, yy + rect.h), die);
        }
    } else {
        if (Config.ESP.Health) {
            
    monoString* Nick = get_NickName(closestEnemy);
    std::string names;

    if (Nick != nullptr) {
        int nick_Len = Nick->getLength();
        for (int i = 0; i < nick_Len; i++) {
            char data = get_Chars(Nick, i);
            names += isascii(data) ? data : '?';
        }
    }

    // 🔹 Scale chung (Xa thì to, gần thì nhỏ)
    float scale = std::clamp(1.0f + (distance / 500.0f), 0.8f, 2.0f);

    // 🔹 Scale chữ (Xa to, gần nhỏ)
    float textScale = std::clamp(1.0f - (distance / 1000.0f), 0.6f, 1.0f);

    // --- BOX Thông Tin ---
    float infoBoxWidth = 150 * scale;  
    float infoBoxHeight = 40 * scale;
    float infoX = rect.x + (rect.w / 2) - (infoBoxWidth / 2);
    float infoY = rect.y - infoBoxHeight - 10 * scale;

    // 🔹 Vẽ khung nền đen
    
    // 🔹 Hiển thị tên người chơi (Bên trái)
    draw->AddText(nullptr, 18 * textScale, ImVec2(infoX + 5, infoY + 10),  
                  ImColor(255, 255, 255, 255), names.c_str());

    // 🔹 Hiển thị khoảng cách (Nằm cuối khung ESP)
    std::string distanceText = "[" + std::to_string((int)distance) + "M]";
    ImVec2 textSize = ImGui::CalcTextSize(distanceText.c_str());

    // Đặt khoảng cách sát mép phải của khung
    float distanceX = infoX + infoBoxWidth - textSize.x - 5; // Sát mép phải
    float distanceY = infoY + 10; // Cùng hàng với tên

    draw->AddText(nullptr, 16 * textScale, ImVec2(distanceX, distanceY),  
                  ImColor(255, 255, 255, 255), distanceText.c_str());

    // --- Thanh Máu ---
    float healthBarWidth = infoBoxWidth;  
    float healthBarHeight = std::max(5 * scale, 3.0f);
    float healthX = infoX;
    float healthY = infoY + infoBoxHeight * 0.8f;

    // 🔹 Viền thanh máu
    draw->AddRectFilled(ImVec2(healthX, healthY),  
                        ImVec2(healthX + healthBarWidth, healthY + healthBarHeight),  
                        ImColor(0, 0, 0, 255));

    // 🔹 Màu thanh máu theo % HP
    int currentHP = GetHp(closestEnemy);
    int maxHP = get_MaxHP(closestEnemy);
    ImColor healthColor = (currentHP > maxHP * 0.6) ? ImColor(0, 255, 0, 255) :   
                          (currentHP > maxHP * 0.3) ? ImColor(255, 255, 0, 255) :  
                          ImColor(255, 0, 0, 255);

    // 🔹 Vẽ thanh máu theo phần trăm HP
    draw->AddRectFilled(ImVec2(healthX, healthY),  
                        ImVec2(healthX + (currentHP / (float)maxHP) * healthBarWidth,  
                               healthY + healthBarHeight),  
                        healthColor);
    }

}

//}

{
 
    ImDrawList* draw = ImGui::GetBackgroundDrawList();

    std::string topText = " TOTAL ENEMIES - ";
    std::string enemiesCount = std::to_string(totalEnemies);
    std::string fullText = topText + enemiesCount + " ";

    std::string icon = ICON_FA_SHIELD " ";

    ImVec2 topTextSize = ImGui::CalcTextSize(fullText.c_str());
    ImVec2 iconSize = ImGui::CalcTextSize(icon.c_str());

    float horizontalPadding = 8.0f; 
    float verticalPadding = 10.0f;

    float totalWidth = (iconSize.x * 2) + topTextSize.x + (horizontalPadding * 2);
    ImVec2 entireBlockPos(g_GlWidth / 2.0f - totalWidth / 2.0f, 65);

    ImVec2 topTextPos(g_GlWidth / 2.0f - topTextSize.x / 2.0f, 65);

    draw->AddRectFilled(ImVec2(topTextPos.x - 5, topTextPos.y - 5), 
    ImVec2(topTextPos.x + topTextSize.x + 5, topTextPos.y + topTextSize.y + 8), 
    ImColor(220, 4, 5, 200), 3.0f);
    
    draw->AddText(NULL, 25.0f, entireBlockPos, ImColor(220, 4, 5, 255), icon.c_str());

    float xPos = entireBlockPos.x + iconSize.x + horizontalPadding;
    draw->AddText(NULL, 25.0f, ImVec2(xPos, entireBlockPos.y), ImColor(255, 255, 255, 255), fullText.c_str());

    xPos += ImGui::CalcTextSize(fullText.c_str()).x;
    xPos += horizontalPadding + 7.0f;

    draw->AddText(NULL, 25.0f, ImVec2(xPos, entireBlockPos.y), ImColor(220, 4, 5, 255), icon.c_str());
}


/*                      
if (totalEnemies >= 0) {
    std::string enemyText = (totalEnemies > 0) ? std::to_string(totalEnemies) : "";

    float fontSize = 40.0f;
    ImFont* font = ImGui::GetFont();
    ImVec2 textSize = font->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, enemyText.c_str());

    ImVec2 center(screenWidth * 0.5f, 50.0f);
    ImVec2 textPos(center.x - textSize.x * 0.5f, center.y - textSize.y * 0.5f);

    ImColor outlineColor(0, 0, 0, 255);
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0)
                draw->AddText(font, fontSize, ImVec2(textPos.x + dx, textPos.y + dy), outlineColor, enemyText.c_str());
        }
    }

    ImColor textColor = (totalEnemies > 0) ? ImColor(255, 50, 50, 255) : ImColor(0, 255, 0, 255);
    draw->AddText(font, fontSize, textPos, textColor, enemyText.c_str());

    
    std::string credit = "";
    float creditFontSize = 20.0f; 

    ImVec2 creditSize = font->CalcTextSizeA(creditFontSize, FLT_MAX, 0.0f, credit.c_str());
    ImVec2 creditPos(screenWidth * 0.5f - creditSize.x * 0.5f, screenHeight - 30.0f);

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0)
                draw->AddText(font, creditFontSize, ImVec2(creditPos.x + dx, creditPos.y + dy), ImColor(0, 0, 0, 255), credit.c_str());
        }
    }

    draw->AddText(font, creditFontSize, creditPos, ImColor(255, 255, 255, 255), credit.c_str());
}

*/
                        }
                    }
                }
            }
        }
    }

}