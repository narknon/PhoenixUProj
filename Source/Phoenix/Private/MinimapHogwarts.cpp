#include "MinimapHogwarts.h"

class UObject;
class UTexture2D;

void UMinimapHogwarts::TextureLoadedCallback(UTexture2D* Texture, UObject* Param) {
}

void UMinimapHogwarts::SetCurrentFloor(int32 Floor) {
}

void UMinimapHogwarts::Init(bool LoadNavMesh) {
}

FVector2D UMinimapHogwarts::GetTopLeftBound() {
    return FVector2D{};
}

FVector UMinimapHogwarts::GetDebugPlayerOffset() {
    return FVector{};
}

int32 UMinimapHogwarts::GetCurrentFloor() {
    return 0;
}

FVector2D UMinimapHogwarts::GetBottomRightBound() {
    return FVector2D{};
}

void UMinimapHogwarts::ChangeLevel(int32 LevelIndex, bool fromInit) {
}

UMinimapHogwarts::UMinimapHogwarts() {
    this->ZLevelData = NULL;
}

