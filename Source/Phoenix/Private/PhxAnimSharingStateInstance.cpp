#include "PhxAnimSharingStateInstance.h"

UPhxAnimSharingStateInstance::UPhxAnimSharingStateInstance() {
    this->bIsFemale = true;
    this->bUseEyeAnims = false;
    this->bUseMouthAnims = false;
    this->bFullBodyAnimHasEyes = false;
    this->bFullBodyAnimHasMouth = false;
    this->FemalePoseAsset = NULL;
    this->MalePoseAsset = NULL;
    this->ActivePoseAsset = NULL;
    this->ActiveEyeAsset = NULL;
    this->FacialAnimationToPlay = NULL;
    this->UseFacialAnimation = FACIAL_ANIM_NONE;
}

