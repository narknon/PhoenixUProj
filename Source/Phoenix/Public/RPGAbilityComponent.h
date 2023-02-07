#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "ActiveAbility.h"
#include "RPGAbilityComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URPGAbilityComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemoveAbilityUI, const FString&, SourceID, int32, SlotNo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnChangeAbilityUI, const FString&, SourceID, int32, SlotNo, float, CurrentTicks, float, MaxTicks);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAddAbilityUI, const FString&, SourceID, int32, SlotNo, float, Ticks);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAddAbilityUI NotifyUIAdd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnChangeAbilityUI NotifyUIChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRemoveAbilityUI NotifyUIRemove;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGuid, FActiveAbility> ActiveAbilities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CooldownGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FGuid> CurrentlyLoading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AbilityTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTickOnScheduler;
    
public:
    URPGAbilityComponent();
    UFUNCTION(BlueprintCallable)
    void RemoveAbility(const FGuid& AbilityID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable)
    void OnEndOfDay();
    
public:
    UFUNCTION(BlueprintCallable)
    static bool HasAbilityTagBP(const AActor* Owner, FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    bool CanAddAbility(FName AbilityName);
    
    UFUNCTION(BlueprintCallable)
    FGuid AddAbility(FName AbilityName, bool bForceSyncLoad);
    
};

