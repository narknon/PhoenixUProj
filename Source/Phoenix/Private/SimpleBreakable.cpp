#include "SimpleBreakable.h"
#include "ObjectStateComponent.h"

ASimpleBreakable::ASimpleBreakable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ObjectState = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
}

