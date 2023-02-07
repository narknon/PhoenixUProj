#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "VariantMapHandle.h"
#include "Ability_Character_Interface.h"
#include "Base_Character.h"
#include "NPCCustomAbilityFinishedDelegate.h"
#include "Templates/SubclassOf.h"
#include "NonCombat_Character.generated.h"

class UAblAbility;
class UAblReactionComponent;
class UAblReactionData;
class UCapsuleComponent;
class UCognitionStimuliSourceComponent;
class UCustomizableCharacterComponent;
class UInteractionArchitectAsset;
class UNPC_ReactionComponent;
class UObject;
class USocialAgentPathFollowerComponent;

UCLASS(Blueprintable)
class ANonCombat_Character : public ABase_Character, public IAbility_Character_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GroupTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USocialAgentPathFollowerComponent* SocialAgentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CCComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CogSourceComp;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNPC_ReactionComponent* NPCReactionComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowDBInstanceRedirect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCreateScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DefaultWorldID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCCustomAbilityFinished CustomAbilityFinishedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* DefaultMunition;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVariantMapHandle NPCVariantMapHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> IdleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveStartAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> PivotAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> StairAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveStopAbility;
    
    ANonCombat_Character();
    UFUNCTION(BlueprintCallable)
    void UnregisterForInteractionSense(UObject* InObject);
    
    UFUNCTION(BlueprintCallable)
    void Suspend(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void StopCustomAbility();
    
    UFUNCTION(BlueprintCallable)
    void StopAndIdle(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartChildSpawnFX(FTransform inSpawnLoc);
    
    UFUNCTION(BlueprintCallable)
    void Resume(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void Release(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void RegisterForInteractionSense(UObject* InObject);
    
    UFUNCTION(BlueprintCallable)
    void PlayCustomAbility(TSubclassOf<UAblAbility> InAbility, bool bPreventReactions);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStationOnFinishedExit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStationOnFinishedEnter();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnReactionQueued(UAblReactionData* InReactionData, UAblReactionComponent* InReactionComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnReactionEnd(UAblReactionData* InReactionData, UAblReactionComponent* InReactionComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnChildSpawnFX(FTransform inSpawnLoc);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSuspended() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsScheduledEntity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReleased() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFrozen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlive() const;
    
    UFUNCTION(BlueprintCallable)
    void HandleRagdollImpact(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UCapsuleComponent* GetNpcCapsuleComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetImpactLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetImpactDirection() const;
    
    UFUNCTION(BlueprintCallable)
    void Freeze(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void ForceScheduledEntityState();
    
    UFUNCTION(BlueprintCallable)
    void ForceProtego(bool inProtegoOnOff);
    
    UFUNCTION(BlueprintCallable)
    void EnableCallout(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void DisableCallout(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplySpawnFX();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyReplicaFX();
    
    
    // Fix for true pure virtual functions not being implemented
};

