#include "MaterialSwapMeshStatesFireAndForgetComponent.h"

class AActor;
class UMaterialSwapMeshState;
class UMaterialSwapMeshStatesFireAndForgetComponent;

void UMaterialSwapMeshStatesFireAndForgetComponent::RestartMeshStates(const TArray<UMaterialSwapMeshState*>& MeshStates) {
}

UMaterialSwapMeshStatesFireAndForgetComponent* UMaterialSwapMeshStatesFireAndForgetComponent::CreateMeshStatesFireAndForgetComponentRules(AActor* Owner, AActor* Target, const TArray<UMaterialSwapMeshState*>& MeshStates, FMaterialSwapRules UseRules, bool bAutoUpdate, FName Tag) {
    return NULL;
}

UMaterialSwapMeshStatesFireAndForgetComponent* UMaterialSwapMeshStatesFireAndForgetComponent::CreateMeshStatesFireAndForgetComponent(AActor* Owner, AActor* Target, const TArray<UMaterialSwapMeshState*>& MeshStates, bool bShouldIncludeChildren, bool bAutoUpdate, FName Tag) {
    return NULL;
}

UMaterialSwapMeshStatesFireAndForgetComponent::UMaterialSwapMeshStatesFireAndForgetComponent() {
    this->bUseRules = false;
    this->bIncludeChildren = true;
    this->bUpdateOnTick = true;
}

