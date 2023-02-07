#include "SimpleBreakable.h"
#include "ObjectStateComponent.h"

ASimpleBreakable::ASimpleBreakable() {
    this->ObjectState = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
}

