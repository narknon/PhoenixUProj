#include "Lockable.h"

void ALockable::Unseal(bool ShowLockWhenLocked, bool Locked, bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects) {
}

void ALockable::Unlock(bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects) {
}

void ALockable::SetLocked(bool Locked, bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects) {
}

void ALockable::SetIsLocked(bool Locked) {
}

void ALockable::Seal(bool ShowLockWhenLocked, bool PlaySoundsAndEffects) {
}

void ALockable::RunDoorConstructionScript() {
}

void ALockable::Lock(bool PlaySoundsAndEffects) {
}

bool ALockable::GetIsLocked() const {
    return false;
}

ALockable::ALockable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->OpeningCharacter = NULL;
    this->IsLocked = false;
    this->SharedCognitionStimuliSource = NULL;
    this->SerializedVersion = 3;
}

