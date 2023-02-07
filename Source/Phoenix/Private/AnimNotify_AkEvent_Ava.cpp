#include "AnimNotify_AkEvent_Ava.h"

UAnimNotify_AkEvent_Ava::UAnimNotify_AkEvent_Ava() {
    this->AkAudioEvent = NULL;
    this->bFollow = true;
    this->MaxDistanceToListener = 3000.00f;
    this->OcclusionOption = OcclusionTick;
    this->OcclusionMethod = EOcclusionTestMethod::EdgeOnPortal_12;
    this->bAutoDestroy = true;
    this->bTickSpatialVolumes = false;
    this->bOnlyWhenMovingOnGround = false;
    this->bUseMotionListener = false;
    this->bUsePlayerOrientatedMotionListener = false;
    this->bOnlyPlayer = false;
}

