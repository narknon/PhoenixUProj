#include "MinimapDungeon.h"

class UObject;
class UTexture2D;

void UMinimapDungeon::TextureLoadedCallback(UTexture2D* Texture, UObject* Param) {
}

void UMinimapDungeon::Init(bool LoadNavMesh) {
}

void UMinimapDungeon::ChangeLevel(int32 LevelIndex, bool fromInit) {
}

UMinimapDungeon::UMinimapDungeon() {
    this->BlackTexture = NULL;
    this->DungeonMap = NULL;
    this->DungeonTextureBlitter = NULL;
    this->MapTexture = NULL;
    this->RevealTexture = NULL;
    this->SeenTexture = NULL;
}

