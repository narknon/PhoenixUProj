#include "PhoenixPlayerController.h"

void APhoenixPlayerController::MapCaptureStart() {
}

APhoenixPlayerController::APhoenixPlayerController() {
    this->TriggerEffectManager = NULL;
    this->LEDEffects = NULL;
    this->PlayerHouseLEDFadeEffect = NULL;
    this->DamageTakenLEDEffect = NULL;
    this->pPlayerHouseLEDFadeEffect = NULL;
    this->pDamageTakenLEDEffect = NULL;
    this->m_pPhoenixHUD = NULL;
    this->m_pEncounterTracker = NULL;
}

