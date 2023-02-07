#include "LockManagerInterface.h"

void ULockManagerInterface::Unlock(FName LockId) {
}

void ULockManagerInterface::SetLock(FName LockId, ELockStates NewState) {
}

void ULockManagerInterface::Lock(FName LockId) {
}

bool ULockManagerInterface::IsUnlockedPure(FName LockId) {
    return false;
}

bool ULockManagerInterface::IsUnlocked(FName LockId) {
    return false;
}

bool ULockManagerInterface::IsLockedPure(FName LockId) {
    return false;
}

bool ULockManagerInterface::IsLocked(FName LockId) {
    return false;
}

ELockStates ULockManagerInterface::GetState(FName LockId) {
    return ELockStates::Unlocked;
}

void ULockManagerInterface::BranchState(FName LockId, EMinimalLockState& LockState) {
}

ULockManagerInterface::ULockManagerInterface() {
}

