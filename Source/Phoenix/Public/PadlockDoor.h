#pragma once
#include "CoreMinimal.h"
#include "Door.h"
#include "ELockDifficulty.h"
#include "PadlockDoor.generated.h"

class ULockableComponent;

UCLASS(Blueprintable)
class APadlockDoor : public ADoor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULockableComponent* LockableComponent;
    
public:
    APadlockDoor();
    UFUNCTION(BlueprintCallable)
    void SetLockedAndDifficulty(bool Locked, ELockDifficulty Difficulty, bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects, bool DoChild);
    
    UFUNCTION(BlueprintCallable)
    void SetLockDifficulty(ELockDifficulty Difficulty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ELockDifficulty GetLockDifficulty() const;
    
};

