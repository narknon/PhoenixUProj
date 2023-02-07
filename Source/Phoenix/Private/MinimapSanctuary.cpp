#include "MinimapSanctuary.h"

class UObject;
class UTexture2D;

void UMinimapSanctuary::TextureLoadedCallback(UTexture2D* Texture, UObject* Param) {
}

void UMinimapSanctuary::SetMapType(ESanctuaryMiniMapType::Type MapType, bool LoadNavMesh, bool fromInit) {
}

void UMinimapSanctuary::SetHubLevelUnlock(const FString& NameOfUnlock, bool LoadTexture, bool FromLoadGame) {
}

void UMinimapSanctuary::Init(bool LoadNavMesh) {
}

void UMinimapSanctuary::ChangeLevel(int32 LevelIndex, bool fromInit) {
}

UMinimapSanctuary::UMinimapSanctuary() {
    this->BlackTexture = NULL;
}

