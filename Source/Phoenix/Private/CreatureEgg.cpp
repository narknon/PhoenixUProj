#include "CreatureEgg.h"
#include "ObjectStateComponent.h"

ACreatureEgg::ACreatureEgg(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ObjectStateComponent = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
}

