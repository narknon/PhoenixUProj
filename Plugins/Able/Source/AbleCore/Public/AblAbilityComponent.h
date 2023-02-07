#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "AblUberAbility.h"
#include "EAblAbilityStartResult.h"
#include "EAblAbilityTaskResult.h"
#include "AblAbilityComponent.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityAsset;
class UAblAbilityContext;
class UAbleSettings;
class USkeletalMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABLECORE_API UAblAbilityComponent : public UActorComponent, public IGameplayTagAssetInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GlobalMeshScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Verbose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblAbilityAsset* AblAbilityAsset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAbleSettings> m_Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer m_TagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblUberAbility AblUberAbility;
    
public:
    UAblAbilityComponent();
    UFUNCTION(BlueprintCallable)
    void UnpauseAllAbilities();
    
    UFUNCTION(BlueprintCallable)
    static void TriggerAbleEvent(const AActor* AbleOwner, const AActor* AbleSender, const FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnorePlayAbility(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTag(const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void PauseAllAbilities();
    
    UFUNCTION(BlueprintCallable)
    void PauseAbility(bool bEnable, const UAblAbility* Abilit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MatchesQuery(const FGameplayTagQuery Query) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MatchesAnyTag(const FGameplayTagContainer Container) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MatchesAllTags(const FGameplayTagContainer Container) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayingAbility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPassiveActive(const UAblAbility* Ability) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsAbilityPaused(const UAblAbility* Ability);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTag(const FGameplayTag Tag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAbilityAnimation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetGameplayTagContainerBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAblAbility* GetActiveAbility_New(const FName ChannelName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAblAbility* GetActiveAbility() const;
    
    UFUNCTION(BlueprintCallable)
    void CancelAllAbilities(EAblAbilityTaskResult ResultToUse, bool bHideActor);
    
    UFUNCTION(BlueprintCallable)
    void CancelAbilityChannel(const FName& ChannelName, TEnumAsByte<EAblAbilityTaskResult> ResultToUse, bool bHideActor);
    
    UFUNCTION(BlueprintCallable)
    void CancelAbility(const UAblAbility* Ability, TEnumAsByte<EAblAbilityTaskResult> ResultToUse);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAblAbilityStartResult CanActivateAbility(UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAblAbilityStartResult BranchAbility(UAblAbilityContext* Context);
    
    UFUNCTION(BlueprintCallable)
    void AddTag(const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void ActorHiddenTimeout();
    
    UFUNCTION(BlueprintCallable)
    EAblAbilityStartResult ActivateAbility(UAblAbilityContext* Context);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override PURE_VIRTUAL(HasMatchingGameplayTag, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAnyMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(HasAllMatchingGameplayTags, return false;);
    
    UFUNCTION(BlueprintCallable)
    void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override PURE_VIRTUAL(GetOwnedGameplayTags,);
    
};

