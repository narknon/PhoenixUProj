#include "CameraStackInput.h"

bool UCameraStackInput::IsLooking() const {
    return false;
}

bool UCameraStackInput::HasAnyMouseLookInput() const {
    return false;
}

bool UCameraStackInput::HasAnyLookInput() const {
    return false;
}

float UCameraStackInput::GetZoom() const {
    return 0.0f;
}

FVector2D UCameraStackInput::GetWalk(bool bInvertX, bool bInvertY) const {
    return FVector2D{};
}

FVector2D UCameraStackInput::GetTilt() const {
    return FVector2D{};
}

float UCameraStackInput::GetRoll() const {
    return 0.0f;
}

bool UCameraStackInput::GetResetPressed() const {
    return false;
}

bool UCameraStackInput::GetQuickTurnPressed() const {
    return false;
}

float UCameraStackInput::GetPedestal() const {
    return 0.0f;
}

FVector2D UCameraStackInput::GetMouseLook(bool bInvertX, bool bInvertY) const {
    return FVector2D{};
}

FVector2D UCameraStackInput::GetLook(bool bInvertX, bool bInvertY) const {
    return FVector2D{};
}

ELastCameraInput UCameraStackInput::GetLastCameraInput() const {
    return ELastCameraInput::None;
}

float UCameraStackInput::GetFocusDistance() const {
    return 0.0f;
}

FVector2D UCameraStackInput::GetDollyAndTruck() const {
    return FVector2D{};
}

UCameraStackInput::UCameraStackInput() {
}

