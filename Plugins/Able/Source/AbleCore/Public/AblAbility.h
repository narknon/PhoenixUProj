#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "AblQueryResult.h"
#include "EAblAbilityTaskRealm.h"
#include "AblAbility.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityContext;
class UAblAbilityEvent;
class UAblAbilityTask;
class UAblChannelingBase;
class UAblTargetingBase;

UCLASS(Blueprintable)
class ABLECORE_API UAblAbility : public UObject {
    GENERATED_BODY()
public:
    void PostLoad() override;
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Length;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_Cooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_PlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_bOverrideGlobalPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_IsPassive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_MaxStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_RefreshDurationOnNewStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_AlwaysRefreshDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_OnlyRefreshLoopTime;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_RequiresAllTasksComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_Loop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_LoopStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_LoopEnd;
    
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 m_LoopMaxIterations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_RequiresTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblTargetingBase* m_Targeting;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_IsChanneled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblChannelingBase*> m_ChannelConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_MustPassAllChannelConditions;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer m_TagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_Tasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityEvent*> m_Events;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 m_AbilityNameHash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EAblAbilityTaskRealm m_AbilityRealm;
    
public:
    UAblAbility();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RequiresTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RequiresAllTasksComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RefreshLoopTimeOnly() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RefreshDurationOnNewStack() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawnedActorEvent(const UAblAbilityContext* Context, const FName& EventName, AActor* SpawnedActor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRaycastEvent(const UAblAbilityContext* Context, const FName& EventName, const TArray<FHitResult>& HitResults) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAblAbility* OnGetBranchAbility(const UAblAbilityContext* Context, const FName& EventName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCustomEvent(const UAblAbilityContext* Context, const FName& EventName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCollisionEvent(const UAblAbilityContext* Context, const FName& EventName, const TArray<FAblQueryResult>& HitEntities) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAbilityStart(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAbilityInterrupt(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAbilityEnd(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAbilityBranch(const UAblAbilityContext* Context, const UAblAbility* NextAbility) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MustPassAllChannelConditions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPassive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLooping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsChanneled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetMaxStacks(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetLoopRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLoopMaxIterationsBP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetDisplayName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCooldown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBasePlayRate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBaseMaxStacks() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBaseCooldown() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetAbilityTagContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CustomTargetingFindTargets(const UAblAbilityContext* Context, TArray<AActor*>& FoundTargets) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CustomFilterCondition(const UAblAbilityContext* Context, const FName& EventName, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CustomCanLoopExecute(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CustomCanBranchTo(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CustomCanAbilityExecute(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CheckCustomChannelConditional(const UAblAbilityContext* Context, const FName& EventName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanInterruptAbility(const UAblAbilityContext* Context, const UAblAbility* CurrentAbility) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float CalculateDamageForActor(const UAblAbilityContext* Context, const FName& EventName, float BaseDamage, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float CalculateCooldown(const UAblAbilityContext* Context) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AlwaysRefreshDuration() const;
    
};

