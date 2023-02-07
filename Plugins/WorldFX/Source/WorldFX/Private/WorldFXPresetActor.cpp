#include "WorldFXPresetActor.h"
#include "WorldFXPresetComponent.h"

void AWorldFXPresetActor::SetSpawnAttachedOverride(bool bNewSpawnAttached) {
}

void AWorldFXPresetActor::ResetCascadeParameters() {
}

void AWorldFXPresetActor::RefreshCascadeParameters() {
}

void AWorldFXPresetActor::GetSpawnAttached(bool& bIsSpawnAttached) {
}

void AWorldFXPresetActor::ForceRefreshPreview() {
}

void AWorldFXPresetActor::ClearSpawnAttachedOverride(bool bNewSpawnAttached) {
}

AWorldFXPresetActor::AWorldFXPresetActor() {
    this->FXComponent = CreateDefaultSubobject<UWorldFXPresetComponent>(TEXT("WorldFXComponent"));
}

