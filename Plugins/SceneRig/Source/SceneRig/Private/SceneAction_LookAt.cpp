#include "SceneAction_LookAt.h"

USceneAction_LookAt::USceneAction_LookAt() {
    this->Priority = ESceneAction_LookAtPriority::Passive;
    this->BlendInTime = NULL;
    this->BlendOutTime = NULL;
    this->TimeDelay = NULL;
    this->KeepStateOnCompletion = NULL;
    this->HeadLookAtAlpha = NULL;
    this->HeadLookAtPlacement = NULL;
    this->HeadYawOffset = NULL;
    this->HeadPitchOffset = NULL;
    this->LoosenessMultiplier = NULL;
    this->TrackingSpeedMultiplier = NULL;
    this->SpineMobility = NULL;
    this->ApplyConstraints = NULL;
    this->EyeLookAtAlpha = NULL;
    this->EyeLookAtAdditive = NULL;
    this->EyeLookAtPlacement = NULL;
    this->BlinkAlpha = NULL;
    this->BlinkNow = NULL;
    this->MicroDartsAlpha = NULL;
    this->GazeState = GazeStatesEnum::RANDOM_BY_WEIGHT;
    this->EyeYawOffset = NULL;
    this->EyePitchOffset = NULL;
    this->IdleAimEyes = NULL;
    this->ListeningAimEyes = NULL;
    this->SpeakingAimEyes = NULL;
}

