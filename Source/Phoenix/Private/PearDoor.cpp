#include "PearDoor.h"
#include "PearLockComponent.h"

class UObject;

void APearDoor::TickleThePear(const UObject* Caller) {
}

APearDoor::APearDoor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LockableComponent = CreateDefaultSubobject<UPearLockComponent>(TEXT("LockableComponent"));
}

