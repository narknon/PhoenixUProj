#include "Enemy_TurnInPlaceData.h"

FEnemy_TurnInPlaceData::FEnemy_TurnInPlaceData() {
    this->Cooldown = 0.00f;
    this->IgnoreCooldownAngle = 0.00f;
    this->StartAngleTolerance = 0.00f;
    this->bFixedBlendspaceAngle = false;
    this->SupportedBlendspaceAngles = 0;
    this->StartMode = ENPC_MobilityTurnAssistStartMode::None;
    this->DelayedStartTime = 0.00f;
}

