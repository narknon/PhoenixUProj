#include "UIDummyActor.h"
#include "ObjectStateComponent.h"



AUIDummyActor::AUIDummyActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ObjectStateComponent = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
    this->DesiredVisibility = false;
}

