#include "SceneAction_GameOptions.h"

USceneAction_GameOptions::USceneAction_GameOptions() {
    this->Settings = NULL;
    this->ExperienceCategory = ESceneRigCategory::None;
    this->bDisableAllIK = false;
    this->bDisableCameraTransparency = true;
    this->bDisablePlayerControl = false;
    this->bPauseStreaming = true;
    this->bDisableInteriorExterior = false;
    this->bDisableCognitionHilighting = true;
    this->bDisableCharactersInSceneTargetableByAi = true;
    this->CharactersInSceneTargetableByAiPriority = EStandardManagedPriority::PassiveCinematic;
    this->MuteMissionGossipPriority = EStandardManagedPriority::ActiveCinematic;
    this->bMuteMissionGossip = false;
    this->bUntetherSeatFillerFillRate = false;
    this->bDisablePauseMenu = true;
    this->bDisableCameraShake = true;
    this->bHideNonCinematicElements = true;
    this->bPauseComboTimeout = false;
    this->bDisablePhotoMode = true;
    this->bPauseNotifications = false;
    this->AudioPriorityCutoffOverride = -1;
    this->AudioPrioritySuppressOverride = -1;
    this->PauseStreamingPlatforms = 15;
    this->PausePopulationManager = 0;
    this->PauseKnowledgeSavings = 0;
    this->PauseInteractionSystem = 0;
    this->PauseWorldEvents = 0;
    this->PauseBeaconSystem = 0;
    this->PauseFootPlantEffects = 0;
    this->PauseEnemyAIComponent = 0;
    this->PrecipitationPercentage = 100.00f;
    this->PrecipitationFadeTime = 1.50f;
    this->MaxWindSpeed = 12.00f;
    this->bSetPrecipitationState = false;
    this->bSetMaxWindSpeed = false;
}

