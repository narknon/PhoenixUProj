#include "InteractiveObjectActor.h"
#include "ObjectStateComponent.h"

AInteractiveObjectActor::AInteractiveObjectActor() {
    this->ObjectState = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
}

