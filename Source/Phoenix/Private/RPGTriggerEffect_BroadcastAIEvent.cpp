#include "RPGTriggerEffect_BroadcastAIEvent.h"

URPGTriggerEffect_BroadcastAIEvent::URPGTriggerEffect_BroadcastAIEvent() {
    this->Owner = NULL;
    this->EventIntensity = EGameEvent_Intensity::Yellow;
    this->Duration = 1.00f;
    this->Range = -1.00f;
    this->TriggerChance = 10.00f;
}

