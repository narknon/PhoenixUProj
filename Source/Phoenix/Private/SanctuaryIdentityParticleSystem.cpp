#include "SanctuaryIdentityParticleSystem.h"

void ASanctuaryIdentityParticleSystem::OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity) {
}

ASanctuaryIdentityParticleSystem::ASanctuaryIdentityParticleSystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoSwapWhenIdentityChanges = false;
    this->ParticleSystemComponent = NULL;
    this->LoadedAsset = NULL;
}

