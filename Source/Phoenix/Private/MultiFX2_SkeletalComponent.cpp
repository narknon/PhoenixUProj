#include "MultiFX2_SkeletalComponent.h"

UMultiFX2_SkeletalComponent::UMultiFX2_SkeletalComponent() {
    this->SkeletalMesh = NULL;
    this->Anim = NULL;
    this->bLooped = false;
    this->bAttached = false;
    this->bIgnoreDeactivate = false;
}

