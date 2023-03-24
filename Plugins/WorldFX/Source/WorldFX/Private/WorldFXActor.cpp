#include "WorldFXActor.h"
#include "WorldFXComponent.h"

void AWorldFXActor::SetSpawnAttached(bool bNewSpawnAttached) {
}

void AWorldFXActor::ResetCascadeParameters() {
}

void AWorldFXActor::RefreshCascadeParameters() {
}

void AWorldFXActor::GetSpawnAttached(bool& bIsSpawnAttached) {
}

void AWorldFXActor::ForceRefreshPreview() {
}

AWorldFXActor::AWorldFXActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FXComponent = CreateDefaultSubobject<UWorldFXComponent>(TEXT("WorldFXComponent"));
}

