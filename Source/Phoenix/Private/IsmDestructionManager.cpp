#include "IsmDestructionManager.h"

class AActor;
class AMunitionType_Base;
class UIsmDestructionManager;
class UStaticMesh;

void UIsmDestructionManager::RegisterMapping(const TSoftObjectPtr<UStaticMesh>& InStaticMesh, const TSoftClassPtr<AActor>& InDestructibleActor) {
}

UIsmDestructionManager* UIsmDestructionManager::Get() {
    return NULL;
}

bool UIsmDestructionManager::ConvertInstanceIfNecessary(AActor* HitTarget, const FBox& Box, float Damage, const FHitResult& HitResult, AActor* Instigator, AMunitionType_Base* Munition) {
    return false;
}

UIsmDestructionManager::UIsmDestructionManager() {
}

