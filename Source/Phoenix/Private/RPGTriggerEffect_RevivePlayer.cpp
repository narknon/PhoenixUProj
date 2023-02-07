#include "RPGTriggerEffect_RevivePlayer.h"

URPGTriggerEffect_RevivePlayer::URPGTriggerEffect_RevivePlayer() {
    this->FadeDelay = 0.50f;
    this->Delay = 1.00f;
    this->RestoreFadeTime = 1.00f;
    this->Cooldown = 300.00f;
    this->invulnerableTime = 2.00f;
    this->RestorePercentHealth = 0.50f;
    this->TriggerEffect = NULL;
    this->UserWidgetSubclass = NULL;
    this->UserWidget = NULL;
}

