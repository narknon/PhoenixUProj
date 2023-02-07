#include "SceneAction_DisableIK.h"

USceneAction_DisableIK::USceneAction_DisableIK() {
    this->bDisableIK = true;
    this->bDisableFloorContact = false;
    this->bDisableLookAt = false;
    this->bDisablePoseFixup = false;
    this->IKPriority = EStandardManagedPriority::ActiveCinematic;
    this->BlendOutDuration = NULL;
    this->BlendInDuration = NULL;
    this->LowestAllowedLookAtPriority = EAnimationDirectionSource::Gameplay;
}

