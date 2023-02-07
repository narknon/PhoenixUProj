#include "UIDummyActor.h"
#include "ObjectStateComponent.h"



AUIDummyActor::AUIDummyActor() {
    this->ObjectStateComponent = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
    this->DesiredVisibility = false;
}

