#include "SanctuaryIdentityParticleSystem.h"

void ASanctuaryIdentityParticleSystem::OnIdentityChanged(ESanctuaryIdentity OldIdentity, ESanctuaryIdentity NewIdentity) {
}

ASanctuaryIdentityParticleSystem::ASanctuaryIdentityParticleSystem() {
    this->bAutoSwapWhenIdentityChanges = false;
    this->ParticleSystemComponent = NULL;
    this->LoadedAsset = NULL;
}

