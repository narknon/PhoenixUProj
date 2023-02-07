#include "CreatureEgg.h"
#include "ObjectStateComponent.h"

ACreatureEgg::ACreatureEgg() {
    this->ObjectStateComponent = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
}

