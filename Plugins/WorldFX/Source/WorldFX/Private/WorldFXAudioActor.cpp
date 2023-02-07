#include "WorldFXAudioActor.h"
#include "WorldFXAudioComponent.h"

void AWorldFXAudioActor::SetSpawnAttached(bool bNewSpawnAttached) {
}

void AWorldFXAudioActor::GetSpawnAttached(bool& bIsSpawnAttached) {
}

void AWorldFXAudioActor::ForceRefreshPreview() {
}

AWorldFXAudioActor::AWorldFXAudioActor() {
    this->SFXComponent = CreateDefaultSubobject<UWorldFXAudioComponent>(TEXT("WorldFXAudioComponent"));
}

