#include "SceneAction_StitchingEnter.h"

USceneAction_StitchingEnter::USceneAction_StitchingEnter() {
    this->Animation = NULL;
    this->PreviousAnimationAction = NULL;
    this->NextAnimationAction = NULL;
    this->StartPlacement = NULL;
    this->EndPlacement = NULL;
    this->EndSpeed = 158.00f;
    this->PreviewPlacement = NULL;
    this->PreviewStartSpeed = 0.00f;
    this->StepsToIterateStartPhases = 0;
    this->StartPhaseRequiresNoMatch = false;
    this->EndPhaseRequiresNoMatch = false;
    this->InBlendTime = 0.20f;
    this->InBlendIsInertial = false;
    this->MidBlendTime = 0.20f;
    this->MidBlendIsInertial = false;
    this->OutBlendTime = 0.20f;
    this->OutBlendIsInertial = false;
    this->PostAnimationInertialBlendTime = 0.00f;
    this->ScaleRootMotion = true;
    this->WarpStride = true;
    this->StrideWarpFactor = 1.00f;
    this->HoldFootPositionWhenPlanted = false;
    this->StrideBias = 0.10f;
    this->ModifySpeedAndDuration = true;
    this->MinCadenceFactor = 0.85f;
    this->MaxCadenceFactor = 1.15f;
    this->MinStrideFactor = 0.40f;
    this->MaxStrideFactor = 1.60f;
    this->StartPhaseOffset = 0.00f;
    this->EndPhaseOffset = 0.00f;
    this->TrapezoidalVelocity = false;
    this->Acceleration = 75.00f;
    this->Deceleration = 75.00f;
    this->CruiseSpeedChoice = ECruiseSpeed::SpecifiedCruisingSpeed;
    this->SpecifiedCruisingSpeed = 158.00f;
    this->CastRayToDetectFloor = false;
    this->VerticalCapsuleOffset = 0.00f;
    this->bExitStitch = false;
    this->ExitTurningRate = 75.00f;
}

