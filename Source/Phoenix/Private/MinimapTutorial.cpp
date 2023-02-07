#include "MinimapTutorial.h"

class UObject;
class UTexture2D;

void UMinimapTutorial::TextureLoadedCallback(UTexture2D* Texture, UObject* Param) {
}

void UMinimapTutorial::Init(bool LoadNavMesh) {
}

void UMinimapTutorial::ChangeLevel(int32 LevelIndex, bool fromInit) {
}

UMinimapTutorial::UMinimapTutorial() {
    this->BlackTexture = NULL;
    this->MapTexture = NULL;
}

