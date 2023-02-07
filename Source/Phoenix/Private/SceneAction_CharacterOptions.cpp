#include "SceneAction_CharacterOptions.h"

USceneAction_CharacterOptions::USceneAction_CharacterOptions() {
    this->OPTIONS = NULL;
    this->bDisableURO = true;
    this->ControlBehaviors = EControlBehaviors::None;
    this->bCancelAbilities = false;
    this->bDisableProceduralEyes = false;
    this->LODOverride = -1;
    this->AlwaysTickPoseAndRefreshBones = false;
    this->BoundsScale = 0.00f;
    this->bEnableReactions = true;
    this->bForceDismount = true;
    this->MovementModePriority = EManagedMovementModePriority::ActiveCinematic;
    this->bUseCustomMovementMode = true;
    this->bSanityCheckTransforms = true;
    this->CollisionResponse = ECharacterOptionsCollisionResponse::DoNotSetCollisionResponse;
    this->SocializationPriority = EStandardManagedPriority::ActiveCinematic;
    this->bDisableSocialization = false;
    this->IKPriority = EStandardManagedPriority::ActiveCinematic;
    this->bEnableIK = false;
    this->bEnableFloorContact = false;
    this->EnableFloorContactProvider = NULL;
    this->bEnableLookat = true;
    this->bEnablePoseFixup = true;
    this->IKBlendDurationOnEnter = 0.00f;
    this->IKBlendDurationOnExit = 0.00f;
    this->LowestAllowedLookAtPriority = EAnimationDirectionSource::CharacterOptions;
    this->bDisablePostProcessBlueprint = false;
    this->ScalePriority = EStandardManagedPriority::ActiveCinematic;
    this->ScaleRootMotion = true;
    this->UnityScale = false;
    this->OverrideRootMotionTranslationScale = false;
    this->RootMotionTranslationScale = 1.00f;
    this->DisableAudioOcclusion = true;
    this->bRemoveSpellEffects = true;
    this->bOverrideDisableSpells = false;
    this->bDisableSpells = false;
    this->bRemoveGuideSpline = true;
    this->DisableSpellsPriority = EStandardManagedPriority::ActiveCinematic;
    this->bSetRightArmState = false;
    this->RightArmState = ERightArmState::HideItem;
    this->bSetLeftArmState = false;
    this->LeftArmState = ELeftArmState::HideItem;
    this->OverrideNPCStateOnFinish = EOverrideNPCStateOnFinish::None;
    this->bOverrideIsTargetableByAi = false;
    this->bIsTargetableByAi = false;
    this->TargetableByAiPriority = EStandardManagedPriority::PassiveCinematic;
    this->bOverrideIsAiSuspended = false;
    this->bSuspendAi = true;
    this->SynchronizationMethodProvider = NULL;
    this->ReleaseFleshLockOnFinish = false;
    this->SynchronizationMethod = ESynchronizeMethod::Synchronize_Schedule;
    this->bSynchronizeLocation = false;
}

