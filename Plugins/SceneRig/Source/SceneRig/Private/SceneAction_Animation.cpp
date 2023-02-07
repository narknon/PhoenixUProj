#include "SceneAction_Animation.h"

USceneAction_Animation::USceneAction_Animation() {
    this->Animation = NULL;
    this->BlendSpaceInput = NULL;
    this->Mask = NULL;
    this->RegisterWithConversation = false;
    this->ReselectOnLoopBoundaries = NULL;
    this->MaxWeight = NULL;
    this->BlendInTime = NULL;
    this->BlendOutTime = NULL;
    this->HoldTime = NULL;
    this->InertialBlendInTime = NULL;
    this->InertialBlendOutTime = NULL;
    this->bBlendOutOnDialogueSkip = false;
    this->bEnableInertializationIfBlendOutSkipped = true;
    this->bAllowLateBlendIn = false;
    this->bSuppressCameraCut = false;
    this->ClothTeleportMode = ESceneAction_ClothingTeleportMode::Teleport;
    this->KeepStateOnCompletion = NULL;
    this->SetupAnimationOnEnter = NULL;
    this->ScaleRootMotion = true;
    this->FemaleShoulderFixupAlpha = NULL;
}

