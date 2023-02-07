#include "NPC_ShowUI.h"

FNPC_ShowUI::FNPC_ShowUI() {
    this->bShowName = false;
    this->bShowHealthBar = false;
    this->bShowBadge = false;
    this->bShowCallout = false;
    this->bShowDamage = false;
    this->bShowPerceptionIndicator = false;
    this->ShowPerceptionIndicatorMode = ENPC_ShowUIPerceptionIndicatorMode::Progression;
    this->ShowMiniMapPerceptionCone = 0;
}

