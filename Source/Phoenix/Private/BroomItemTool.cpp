#include "BroomItemTool.h"

void ABroomItemTool::SpawnAndMountBroom(bool bUseTransition, bool bInDestroyAfterMount) {
}

void ABroomItemTool::OnAnimsLoaded(bool bUseTransition) {
}

void ABroomItemTool::MountBroom(bool bUseTransition) {
}

ABroomItemTool::ABroomItemTool() {
    this->FlyingBroomClass = NULL;
    this->FlyingBroomProp = NULL;
    this->SpeedBoostUnavailableMessageTimeout = 1.50f;
    this->SpeedBoostOnCooldownMessageTimeout = 1.50f;
    this->LoadedAnims = NULL;
}

