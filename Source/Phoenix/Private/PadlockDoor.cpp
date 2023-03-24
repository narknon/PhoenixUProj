#include "PadlockDoor.h"
#include "PadlockComponent.h"

void APadlockDoor::SetLockedAndDifficulty(bool Locked, ELockDifficulty Difficulty, bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects, bool DoChild) {
}

void APadlockDoor::SetLockDifficulty(ELockDifficulty Difficulty) {
}

ELockDifficulty APadlockDoor::GetLockDifficulty() const {
    return ELockDifficulty::Level_1;
}

APadlockDoor::APadlockDoor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LockableComponent = CreateDefaultSubobject<UPadlockComponent>(TEXT("LockableComponent"));
}

