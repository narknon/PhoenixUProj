#include "ParticleFXContainer.h"
#include "Components/SceneComponent.h"

class UNiagaraSystem;
class UParticleSystem;

void AParticleFXContainer::DestroySelf() {
}

void AParticleFXContainer::DeactiveAndDestroyAfterXSeconds(float Seconds) {
}

void AParticleFXContainer::AddParticleEmitter(UParticleSystem* SystemTemplate) {
}

void AParticleFXContainer::AddNiagaraSystem(UNiagaraSystem* SystemTemplate) {
}

AParticleFXContainer::AParticleFXContainer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
}

