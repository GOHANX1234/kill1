#pragma once

// ============================================================================
// ADVANCED FLY SYSTEM - Smooth Jump-Based Flight with CS Bypass
// Based on game's internal FlightRoamState & JetFlyState mechanics
// ============================================================================

#include "Unity/Vector3.hpp"
#include "Unity/Quaternion.h"

// ===== FLY CONFIGURATION =====
bool Fly_Enabled = false;
float Fly_Height = 2.5f;      // Jump height per pulse (2.5 = natural jump feel)
float Fly_Speed = 8.0f;        // Horizontal movement speed
bool Fly_StayAtHeight = false; // Toggle to maintain current height
bool Fly_AutoAscend = true;   // Auto-ascend mode (false = manual control only)
bool Fly_UserWantsUp = false;  // Manual ascend trigger
bool Fly_UserWantsDown = false; // Manual descend trigger

// ===== INTERNAL FLY STATE =====
static bool g_FlyInitialized = false;
static float g_TargetFlyHeight = 0.0f;
static float g_CurrentFlyHeight = 0.0f;
static float g_LastGroundHeight = 0.0f;
static int g_JumpPulseCounter = 0;
static bool g_IsAscending = true;

// ===== UNITY ENGINE OFFSETS =====
#define offset_GetPosition (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_position"), 0)
#define offset_SetPosition (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("set_position"), 1)
#define offset_GetTransform (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_transform"), 0)
#define offset_GetForward (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_forward"), 0)
#define offset_GetRight (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_right"), 0)

// ===== CAMERA OFFSETS =====
#define offset_Camera_GetMain (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.CoreModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Camera"), OBFUSCATE("get_main"), 0)

// ===== RIGIDBODY OFFSETS (for velocity detection) =====
#define offset_GetRigidbody (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.PhysicsModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_rigidbody"), 0)
#define offset_GetVelocity (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.PhysicsModule.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Rigidbody"), OBFUSCATE("get_velocity"), 0)

// ===== HELPER FUNCTIONS =====

static void* GetPlayerTransform(void* player) {
    if (player == nullptr) return nullptr;
    void* (*_GetTransform)(void*) = (void* (*)(void*))(offset_GetTransform);
    return _GetTransform(player);
}

static Vector3 GetPosition(void* transform) {
    if (transform == nullptr) return Vector3::zero();
    Vector3 (*_GetPosition)(void*) = (Vector3 (*)(void*))(offset_GetPosition);
    return _GetPosition(transform);
}

static void SetPosition(void* transform, Vector3 newPos) {
    if (transform == nullptr) return;
    void (*_SetPosition)(void*, Vector3) = (void (*)(void*, Vector3))(offset_SetPosition);
    _SetPosition(transform, newPos);
}

static Vector3 GetForward(void* transform) {
    if (transform == nullptr) return Vector3::zero();
    Vector3 (*_GetForward)(void*) = (Vector3 (*)(void*))(offset_GetForward);
    return _GetForward(transform);
}

static Vector3 GetRight(void* transform) {
    if (transform == nullptr) return Vector3::zero();
    Vector3 (*_GetRight)(void*) = (Vector3 (*)(void*))(offset_GetRight);
    return _GetRight(transform);
}

static void* GetMainCamera() {
    void* (*_GetMain)() = (void* (*)())(offset_Camera_GetMain);
    return _GetMain();
}

static void* GetRigidbody(void* component) {
    if (component == nullptr) return nullptr;
    void* (*_GetRigidbody)(void*) = (void* (*)(void*))(offset_GetRigidbody);
    return _GetRigidbody(component);
}

static Vector3 GetVelocity(void* rigidbody) {
    if (rigidbody == nullptr) return Vector3::zero();
    Vector3 (*_GetVelocity)(void*) = (Vector3 (*)(void*))(offset_GetVelocity);
    return _GetVelocity(rigidbody);
}

static bool IsPlayerMoving(void* player) {
    if (player == nullptr) return false;
    
    void* rigidbody = GetRigidbody(player);
    if (rigidbody == nullptr) return false;
    
    Vector3 velocity = GetVelocity(rigidbody);
    float horizontalSpeed = sqrt(velocity.x * velocity.x + velocity.z * velocity.z);
    
    return horizontalSpeed > 0.1f; // Player is moving if horizontal speed > 0.1
}

// ===== ADVANCED FLY LOGIC =====

// Smooth lerp function for natural movement
static float Lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

// Calculate camera-based movement direction
static Vector3 GetMovementDirection(void* cameraTransform) {
    if (cameraTransform == nullptr) return Vector3::zero();
    
    Vector3 forward = GetForward(cameraTransform);
    forward.y = 0.0f; // Flatten to horizontal plane
    
    // Normalize manually
    float magnitude = sqrt(forward.x * forward.x + forward.z * forward.z);
    if (magnitude > 0.001f) {
        forward.x /= magnitude;
        forward.z /= magnitude;
    }
    
    return forward;
}

// Initialize fly state when first enabled
static void InitializeFly(Vector3 currentPos) {
    g_FlyInitialized = true;
    g_CurrentFlyHeight = currentPos.y;
    g_TargetFlyHeight = currentPos.y;
    g_LastGroundHeight = currentPos.y;
    g_JumpPulseCounter = 0;
    g_IsAscending = true;
}

// Reset fly state when disabled
static void ResetFly() {
    g_FlyInitialized = false;
    g_TargetFlyHeight = 0.0f;
    g_CurrentFlyHeight = 0.0f;
    g_JumpPulseCounter = 0;
}

// ===== MAIN FLY FUNCTION =====
// Call this every frame from your Update hook
void ApplyAdvancedFly(void* player) {
    if (player == nullptr || !Fly_Enabled) {
        if (g_FlyInitialized) {
            ResetFly();
        }
        return;
    }
    
    void* currentMatch = Curent_Match();
    if (currentMatch == nullptr) return;
    
    void* localPlayer = GetLocalPlayer(currentMatch);
    if (localPlayer == nullptr || localPlayer != player) return;
    
    // Get player transform
    void* playerTransform = GetPlayerTransform(player);
    if (playerTransform == nullptr) return;
    
    // Get current position
    Vector3 currentPos = GetPosition(playerTransform);
    
    // Initialize on first run
    if (!g_FlyInitialized) {
        InitializeFly(currentPos);
    }
    
    g_CurrentFlyHeight = currentPos.y;
    
    // ===== VERTICAL MOVEMENT (Jump-like behavior) =====
    float verticalDelta = 0.0f;
    
    if (Fly_StayAtHeight) {
        // Maintain current height with gentle oscillation (looks natural)
        float heightDiff = g_TargetFlyHeight - g_CurrentFlyHeight;
        
        if (abs(heightDiff) > 0.1f) {
            // Smooth height stabilization
            verticalDelta = heightDiff * 0.15f; // Gentle correction
        } else {
            // Add tiny oscillation to mimic natural hover
            g_JumpPulseCounter++;
            float oscillation = sin(g_JumpPulseCounter * 0.1f) * 0.05f;
            verticalDelta = oscillation;
        }
    } else if (Fly_UserWantsDown) {
        // Manual descent
        verticalDelta = -Fly_Height * 0.1f; // Smooth descend
        g_TargetFlyHeight = g_CurrentFlyHeight;
    } else if (Fly_AutoAscend || Fly_UserWantsUp) {
        // Jump-by-jump ascent (natural looking) - only when auto-ascend OR user presses up
        g_JumpPulseCounter++;
        
        // Simulate jump arc (fast up, then slow down)
        int pulsePhase = g_JumpPulseCounter % 20; // 20 frame jump cycle
        
        if (pulsePhase < 10) {
            // Rising phase
            float jumpCurve = 1.0f - (pulsePhase / 10.0f); // 1.0 -> 0.0
            verticalDelta = Fly_Height * 0.15f * jumpCurve; // Decreasing upward velocity
        } else if (pulsePhase < 15) {
            // Peak/hover phase
            verticalDelta = 0.0f;
        } else {
            // Slight dip (natural jump behavior)
            verticalDelta = -Fly_Height * 0.03f;
        }
        
        // Update target height
        if (pulsePhase == 19) {
            g_TargetFlyHeight = g_CurrentFlyHeight;
        }
    } else {
        // IDLE/HOVER: No vertical input - just maintain current position
        g_JumpPulseCounter++;
        float oscillation = sin(g_JumpPulseCounter * 0.1f) * 0.05f;
        verticalDelta = oscillation; // Gentle bob for realism
        g_TargetFlyHeight = g_CurrentFlyHeight;
    }
    
    // ===== HORIZONTAL MOVEMENT (Camera direction) =====
    // ONLY apply horizontal flight when player is already moving!
    Vector3 horizontalMovement = Vector3::zero();
    
    if (IsPlayerMoving(player)) {
        // Player is moving - apply camera-based directional flight
        void* mainCamera = GetMainCamera();
        if (mainCamera != nullptr) {
            void* cameraTransform = GetPlayerTransform(mainCamera);
            if (cameraTransform != nullptr) {
                Vector3 moveDir = GetMovementDirection(cameraTransform);
                
                // Apply movement in camera direction
                horizontalMovement.x = moveDir.x * Fly_Speed * 0.016f; // ~60fps frame time
                horizontalMovement.z = moveDir.z * Fly_Speed * 0.016f;
            }
        }
    }
    // If player is NOT moving (standing still), DON'T push them horizontally!
    
    // ===== APPLY MOVEMENT (Anti-Cheat Bypass) =====
    // Instead of direct teleport, use small incremental movements
    // This mimics natural player physics and bypasses CS detection
    
    Vector3 newPos = currentPos;
    newPos.y += verticalDelta;
    newPos.x += horizontalMovement.x;
    newPos.z += horizontalMovement.z;
    
    // Clamp vertical movement to look natural (avoid instant jumps)
    float maxVerticalChange = 0.5f; // Max 0.5 units per frame
    float actualVerticalChange = newPos.y - currentPos.y;
    if (abs(actualVerticalChange) > maxVerticalChange) {
        newPos.y = currentPos.y + (actualVerticalChange > 0 ? maxVerticalChange : -maxVerticalChange);
    }
    
    // Apply the new position
    SetPosition(playerTransform, newPos);
}

// ===== USER CONTROLS =====

// Call this to toggle fly on/off
void ToggleFly() {
    Fly_Enabled = !Fly_Enabled;
    if (!Fly_Enabled) {
        ResetFly();
    }
}

// Call this to toggle height lock
void ToggleHeightLock() {
    Fly_StayAtHeight = !Fly_StayAtHeight;
    if (Fly_StayAtHeight && g_FlyInitialized) {
        g_TargetFlyHeight = g_CurrentFlyHeight;
    }
}

// Adjust fly height (for UI sliders)
void SetFlyHeight(float height) {
    Fly_Height = height;
}

// Adjust fly speed (for UI sliders)
void SetFlySpeed(float speed) {
    Fly_Speed = speed;
}

// Manual height adjustment
void AdjustTargetHeight(float delta) {
    if (g_FlyInitialized) {
        g_TargetFlyHeight += delta;
        Fly_StayAtHeight = true;
    }
}
