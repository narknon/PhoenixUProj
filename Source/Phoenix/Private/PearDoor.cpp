#include "PearDoor.h"
#include "PearLockComponent.h"

class UObject;

void APearDoor::TickleThePear(const UObject* Caller) {
}

APearDoor::APearDoor() {
    this->LockableComponent = CreateDefaultSubobject<UPearLockComponent>(TEXT("LockableComponent"));
}

