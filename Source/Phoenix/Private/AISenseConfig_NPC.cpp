#include "AISenseConfig_NPC.h"

UAISenseConfig_NPC::UAISenseConfig_NPC() {
    this->bEnabled = true;
    this->UpdateInterval = 0.20f;
    this->EvaluateRadius = 40000.00f;
    this->bStartActive = true;
}

