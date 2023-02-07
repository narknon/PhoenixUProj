#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ELockLevel.h"
#include "LockComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULockComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer KeyContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELockLevel LockLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LockValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConsumeKey;
    
    ULockComponent();
    UFUNCTION(BlueprintCallable)
    bool UnlockWithKey(const FGameplayTagContainer& Key, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    bool Unlock(float UnlockValue, bool bCompleteAttempt);
    
    UFUNCTION(BlueprintCallable)
    void Lock();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetUnlockedPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxLockValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ELockLevel GetLockLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentLockValue() const;
    
};

