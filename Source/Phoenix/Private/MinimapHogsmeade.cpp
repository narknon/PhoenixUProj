#include "MinimapHogsmeade.h"

class UObject;
class UTexture2D;

void UMinimapHogsmeade::TextureLoadedCallback(UTexture2D* Texture, UObject* Param) {
}

void UMinimapHogsmeade::Init(bool LoadNavMesh) {
}

FVector2D UMinimapHogsmeade::GetTopLeftBound() {
    return FVector2D{};
}

FVector UMinimapHogsmeade::GetDebugPlayerOffset() {
    return FVector{};
}

FVector2D UMinimapHogsmeade::GetBottomRightBound() {
    return FVector2D{};
}

void UMinimapHogsmeade::ChangeLevel(int32 LevelIndex, bool fromInit) {
}

UMinimapHogsmeade::UMinimapHogsmeade() {
}

