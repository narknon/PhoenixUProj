#include "InteractiveObjectActor.h"
#include "ObjectStateComponent.h"

AInteractiveObjectActor::AInteractiveObjectActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ObjectState = CreateDefaultSubobject<UObjectStateComponent>(TEXT("ObjectStateComponent"));
}

