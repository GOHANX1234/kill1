#pragma once

// ============================================================================
// SPEED BOOST FEATURE - Non-Hook Offset-Based by @Gohan52
// ============================================================================

bool SpeedBoost_Enabled = false;
float SpeedBoost_Multiplier = 1.5f;

// Offset definitions for Player speed methods
#define offset_GetMoveSpeed (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GetMoveSpeedForFPPMode"), 0)

// Get current player move speed
static float GetPlayerMoveSpeed(void* player) {
    if (player == nullptr) return 0.0f;
    float (*_GetMoveSpeed)(void*) = (float (*)(void*))(offset_GetMoveSpeed);
    return _GetMoveSpeed(player);
}

// Apply Speed Boost to player
void ApplySpeedBoost(void* player) {
    if (player == nullptr || !SpeedBoost_Enabled) return;
    
    void* currentMatch = Curent_Match();
    if (currentMatch == nullptr) return;
    
    void* localPlayer = GetLocalPlayer(currentMatch);
    if (localPlayer == nullptr || localPlayer != player) return;
    
    // Get base movement speed
    float baseSpeed = GetPlayerMoveSpeed(player);
    if (baseSpeed <= 0.0f) return;
    
    // Apply speed multiplier using PhysX manipulation
    // Modify player's movement velocity directly
    void* characterController = *(void**)((uintptr_t)player + 0x380); // m_CharacterController offset
    if (characterController != nullptr) {
        // Boost the player's speed by manipulating internal velocity
        float* speedPtr = (float*)((uintptr_t)player + 0x400); // Speed field offset
        if (speedPtr != nullptr) {
            *speedPtr = baseSpeed * SpeedBoost_Multiplier;
        }
    }
}

// Reset speed to normal
void ResetPlayerSpeed(void* player) {
    if (player == nullptr) return;
    
    float* speedPtr = (float*)((uintptr_t)player + 0x400);
    if (speedPtr != nullptr) {
        *speedPtr = GetPlayerMoveSpeed(player);
    }
}
