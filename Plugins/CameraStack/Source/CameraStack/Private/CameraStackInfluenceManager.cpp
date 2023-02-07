#include "CameraStackInfluenceManager.h"

class UCameraStackInfluenceHandle;
class UCameraStackVolumePreset;

void UCameraStackInfluenceManager::UnregisterInfluence(UCameraStackInfluenceHandle* InHandle) {
}

UCameraStackInfluenceHandle* UCameraStackInfluenceManager::RegisterInfluence(UCameraStackVolumePreset* InPreset, int32 Priority, float MaxBlendSpeed) {
    return NULL;
}

UCameraStackInfluenceManager::UCameraStackInfluenceManager() {
}

