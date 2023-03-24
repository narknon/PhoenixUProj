#include "MapCursor.h"

void AMapCursor::ToggleShowScreenPosition() {
}

void AMapCursor::ToggleShowMouseLocation() {
}

void AMapCursor::ToggleShowCursorLocation() {
}

void AMapCursor::ToggleShowCollisionActor() {
}

void AMapCursor::SetToMouse() {
}

void AMapCursor::SetToGamePad(bool doLerp, FVector lerpLocation) {
}

void AMapCursor::SetScreenBounds(FVector4 BoundsArray) {
}

void AMapCursor::SetRightMouseButtonClicked(bool Clicked) {
}

void AMapCursor::SetCursorControl(TEnumAsByte<ECursorControlTypes::Type>& ControlType) {
}

void AMapCursor::SetCursorBounds(FVector4 BoundsArray) {
}

void AMapCursor::MouseSnapToPlayer() {
}

FVector4 AMapCursor::GetScreenBounds() {
    return FVector4{};
}

bool AMapCursor::GetMouseActive() {
    return false;
}

bool AMapCursor::GetLerpingToNewLocation() {
    return false;
}

bool AMapCursor::GetGamePadActive() {
    return false;
}

FVector AMapCursor::GetCursorTranslation() {
    return FVector{};
}

FVector4 AMapCursor::GetCursorBounds() {
    return FVector4{};
}

void AMapCursor::GamepadSnapToPlayer() {
}

AMapCursor::AMapCursor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CursorSpeedMultiplier = 5000.00f;
    this->CursorSpeedMultiplierDungeon = 2000.00f;
    this->CursorSpeedMultiplierZoomFactor = 1.00f;
    this->CursorSpeedMultiplierZoomFactorDungeon = 1.00f;
    this->ShouldSnapCursor = true;
    this->MaxFadeFromCursor = 0.50f;
    this->FadeDistanceFromCursorToStartFade = 3000.00f;
    this->MaxFadeDistance = 4000.00f;
    this->FadeMultiplier = 20000.00f;
    this->DisableMouseInput = false;
    this->MouseSlop = 0.50f;
    this->SnapToIconLerpFactor = 15.00f;
    this->SnapToIconLerpFactorHogwarts = 15.00f;
    this->VerticalHorinzontalCollideAdjust = 200.00f;
    this->MouseEdgeMovementSpeed = 2.00f;
    this->ShowMouseCursorTop = 80.00f;
    this->VerticalEdgeBoundTop = 120.00f;
    this->VerticalEdgeBoundBottom = 80.00f;
    this->HorizontalEdgeBound = 80.00f;
    this->CursorMoveOnScroll = 2.00f;
    this->ToggleInputLerpFactor = 10.00f;
    this->MaterialInstance = NULL;
    this->CursorMaterial = NULL;
    this->CursorTexture = NULL;
    this->MapScreen = NULL;
    this->UIManager = NULL;
    this->MapSubSystem = NULL;
    this->PlayerController = NULL;
    this->MapBase = NULL;
    this->OverlandMap = NULL;
    this->HogsmeadeMap = NULL;
    this->HogwartsMap = NULL;
    this->MapMoveComponent = NULL;
    this->LocalPlayer = NULL;
    this->TraceWorld = NULL;
    this->HitActor = NULL;
    this->LastHitActor = NULL;
    this->StaticHitComponent = NULL;
    this->LastStaticHitComponent = NULL;
}

