#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ELockStates.h"
#include "EMinimalLockState.h"
#include "LockManagerInterface.generated.h"

UCLASS(Blueprintable)
class ULockManagerInterface : public UObject {
    GENERATED_BODY()
public:
    ULockManagerInterface();
    UFUNCTION(BlueprintCallable)
    static void Unlock(FName LockId);
    
    UFUNCTION(BlueprintCallable)
    static void SetLock(FName LockId, ELockStates NewState);
    
    UFUNCTION(BlueprintCallable)
    static void Lock(FName LockId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUnlockedPure(FName LockId);
    
    UFUNCTION(BlueprintCallable)
    static bool IsUnlocked(FName LockId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsLockedPure(FName LockId);
    
    UFUNCTION(BlueprintCallable)
    static bool IsLocked(FName LockId);
    
    UFUNCTION(BlueprintCallable)
    static ELockStates GetState(FName LockId);
    
    UFUNCTION(BlueprintCallable)
    static void BranchState(FName LockId, EMinimalLockState& LockState);
    
};

