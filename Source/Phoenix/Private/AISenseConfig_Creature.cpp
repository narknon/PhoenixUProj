#include "AISenseConfig_Creature.h"
#include "AISense_Creature.h"

UAISenseConfig_Creature::UAISenseConfig_Creature() {
    this->Implementation = UAISense_Creature::StaticClass();
    this->LowerRadius = 100.00f;
    this->UpperRadius = 1000.00f;
    this->AwarenessMultiplier = 1.00f;
}

