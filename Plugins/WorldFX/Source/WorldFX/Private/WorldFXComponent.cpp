#include "WorldFXComponent.h"

class USceneComponent;
class UWorldFXComponent;

void UWorldFXComponent::SetSpawnAttached(bool bNewSpawnAttached) {
}

void UWorldFXComponent::ResetCascadeParameters() {
}

void UWorldFXComponent::RefreshCascadeParameters() {
}

void UWorldFXComponent::GetSpawnAttached(bool& bIsSpawnAttached) {
}

UWorldFXComponent* UWorldFXComponent::CreateWorldFX(USceneComponent* AttachTo, FWorldFXFull WorldFXSetup, FTransform RelativeTransform) {
    return NULL;
}

UWorldFXComponent::UWorldFXComponent() {
    this->Rule = NULL;
    this->bSpawnAttached = false;
}

