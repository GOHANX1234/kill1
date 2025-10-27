#pragma once

// ============================================================================
// FLY FEATURE - Proper Hook-Based Implementation by @Gohan52
// ============================================================================

bool Fly_Enabled = false;
float Fly_Height = 5.0f;  // Height increment per update
float Fly_Speed = 10.0f;   // Horizontal speed multiplier

// Offsets for Player position and movement
#define offset_GetPosition (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_position"), 0)
#define offset_SetPosition (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("set_position"), 1)
#define offset_GetTransform (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_transform"), 0)

// Get player transform
static void* GetPlayerTransform(void* player) {
    if (player == nullptr) return nullptr;
    void* (*_GetTransform)(void*) = (void* (*)(void*))(offset_GetTransform);
    return _GetTransform(player);
}

// Get current position
static Vector3 GetPlayerPosition(void* transform) {
    if (transform == nullptr) return Vector3::zero();
    Vector3 (*_GetPosition)(void*) = (Vector3 (*)(void*))(offset_GetPosition);
    return _GetPosition(transform);
}

// Set new position
static void SetPlayerPosition(void* transform, Vector3 newPos) {
    if (transform == nullptr) return;
    void (*_SetPosition)(void*, Vector3) = (void (*)(void*, Vector3))(offset_SetPosition);
    _SetPosition(transform, newPos);
}

// Apply Fly - This gets called every frame
void ApplyFly(void* player) {
    if (player == nullptr || !Fly_Enabled) return;
    
    void* currentMatch = Curent_Match();
    if (currentMatch == nullptr) return;
    
    void* localPlayer = GetLocalPlayer(currentMatch);
    if (localPlayer == nullptr || localPlayer != player) return;
    
    // Get player transform
    void* playerTransform = GetPlayerTransform(player);
    if (playerTransform == nullptr) return;
    
    // Get current position
    Vector3 currentPos = GetPlayerPosition(playerTransform);
    
    // Increase Y position to make player fly
    currentPos.y += Fly_Height;
    
    // Set new position
    SetPlayerPosition(playerTransform, currentPos);
}

// Teleport player to specific position (useful for fly mode)
void TeleportPlayer(void* player, Vector3 targetPos) {
    if (player == nullptr) return;
    
    void* playerTransform = GetPlayerTransform(player);
    if (playerTransform == nullptr) return;
    
    SetPlayerPosition(playerTransform, targetPos);
}
