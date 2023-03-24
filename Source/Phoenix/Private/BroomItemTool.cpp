#include "BroomItemTool.h"

void ABroomItemTool::SpawnAndMountBroom(bool bUseTransition, bool bInDestroyAfterMount) {
}

void ABroomItemTool::OnAnimsLoaded(bool bUseTransition) {
}

void ABroomItemTool::MountBroom(bool bUseTransition) {
}

ABroomItemTool::ABroomItemTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FlyingBroomClass = NULL;
    this->FlyingBroomProp = NULL;
    this->SpeedBoostUnavailableMessageTimeout = 1.50f;
    this->SpeedBoostOnCooldownMessageTimeout = 1.50f;
    this->LoadedAnims = NULL;
}

