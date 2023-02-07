#include "ActorMeshSetupLibrary.h"

class AActor;
class UMeshComponent;

void UActorMeshSetupLibrary::ActorMeshSetupRemoveMeshAlwaysIgnore(UMeshComponent* MeshComponent) {
}

void UActorMeshSetupLibrary::ActorMeshSetupRemoveAlwaysIgnore(AActor* Actor, bool bIncludeChildren) {
}

bool UActorMeshSetupLibrary::ActorMeshSetupProcessRefresh(AActor* Actor, bool bIncludeChildren) {
    return false;
}

bool UActorMeshSetupLibrary::ActorMeshSetupProcessNamed(AActor* Actor, FActorMeshSetupName MeshSetup, bool bIncludeChildren) {
    return false;
}

bool UActorMeshSetupLibrary::ActorMeshSetupProcessAuto(AActor* Actor, bool bIncludeChildren) {
    return false;
}

void UActorMeshSetupLibrary::ActorMeshSetupAlwaysIgnoreMesh(UMeshComponent* MeshComponent) {
}

void UActorMeshSetupLibrary::ActorMeshSetupAlwaysIgnore(AActor* Actor, bool bIncludeChildren) {
}

UActorMeshSetupLibrary::UActorMeshSetupLibrary() {
}

