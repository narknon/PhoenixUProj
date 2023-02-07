#include "CreatureMountTransitionActor.h"


void ACreatureMountTransitionActor::OnKnockdownDismountEndCallback() {
}





ACreatureMountTransitionActor::ACreatureMountTransitionActor() {
    this->PlayerMountAbility_Start = NULL;
    this->PlayerMountAbility_Cancel = NULL;
    this->PlayerMountAbility_Standing = NULL;
    this->PlayerMountAbility_Trot = NULL;
    this->PlayerMountAbility_Standing_End_Partial = NULL;
    this->PlayerMountAbility_Trot_End_Partial = NULL;
    this->CreatureAbility_Standing_FromBag = NULL;
    this->CreatureAbility_Trot_FromBag = NULL;
    this->PlayerDismountAbility_Standing_Start = NULL;
    this->PlayerDismountAbility_Trot_Start = NULL;
    this->PlayerDismountAbility_Standing = NULL;
    this->PlayerDismountAbility_Trot = NULL;
    this->PlayerDismountAbility_End = NULL;
    this->CreatureAbility_Standing_ToBag = NULL;
    this->CreatureAbility_Trot_ToBag = NULL;
    this->MountTransitionAnimState = EMountTransitionAnimState::Wait;
    this->bUseCreatureMountBagVFX = false;
    this->MountSkinFXPreload = NULL;
    this->MountSkinFXPreloadMesh = NULL;
    this->RiderCharacter = NULL;
    this->CreatureCharacter = NULL;
    this->SkinFXLoadingBundle = NULL;
}

