#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "PlayerFailedToUnlockLockDelegate.h"
#include "PlayerRemovedLockDelegate.h"
#include "PlayerStartedUnlockingLockDelegate.h"
#include "PlayerUnlockedLockDelegate.h"
#include "PlayerUnlockedLockWithAlohomoraDelegate.h"
#include "PlayerUnlockedLockWithKeyDelegate.h"
#include "Lockable.generated.h"

class AAmbulatory_Character;
class UCognitionStimuliSourceComponent;

UCLASS(Blueprintable)
class ALockable : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAmbulatory_Character* OpeningCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsLocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStartedUnlockingLock OnPlayerStartedUnlockingLock;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerUnlockedLock OnPlayerUnlockedLock;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerUnlockedLockWithAlohomora OnPlayerUnlockedLockWithAlohomora;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerUnlockedLockWithKey OnPlayerUnlockedLockWithKey;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerRemovedLock OnPlayerRemovedLock;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerFailedToUnlockLock OnPlayerFailedToUnlockLock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* SharedCognitionStimuliSource;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid Guid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SerializedVersion;
    
public:
    ALockable();
    UFUNCTION(BlueprintCallable)
    void Unseal(bool ShowLockWhenLocked, bool Locked, bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects);
    
    UFUNCTION(BlueprintCallable)
    void Unlock(bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects);
    
    UFUNCTION(BlueprintCallable)
    void SetLocked(bool Locked, bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects);
    
    UFUNCTION(BlueprintCallable)
    void SetIsLocked(bool Locked);
    
    UFUNCTION(BlueprintCallable)
    void Seal(bool ShowLockWhenLocked, bool PlaySoundsAndEffects);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RunDoorConstructionScript();
    
public:
    UFUNCTION(BlueprintCallable)
    void Lock(bool PlaySoundsAndEffects);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsLocked() const;
    
};

