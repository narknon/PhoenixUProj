#pragma once
#include "CoreMinimal.h"
#include "IKPoseFixupDefinition.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "GameplayTagContainer.h"
#include "EMountMovementState.h"
#include "Templates/SubclassOf.h"
#include "Creature_RiderComponent.generated.h"

class ACreatureMountHandler;
class ACreature_Character;
class UAblAbility;
class UAblReactionAbility;
class UAblReactionComponent;
class UAblReactionData;
class UAnimationArchitectAsset;
class UCreature_MountComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCreature_RiderComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> HeadTurnAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeadTurnAbilityChannelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> FlyAdditiveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FlyAdditiveAbilityChannelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> AbilityChannelsToNotClear;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RiderAnimationSetTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationArchitectAsset* RiderAnimationSetArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MountTypeAnimationArchitectTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSubclassOf<UAblAbility>> HardPlayAbilityMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAblReactionAbility>> CreatureReactionAbilitesForRiderKnockdown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RiderKnockdownMunitionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> InitialGroundAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> InitialFlyingAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseHandIK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKPoseFixupDefinition IKPoseFixupDefinitionLeftHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKPoseFixupDefinition IKPoseFixupDefinitionRightHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAnimationModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HipsBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LeftThighBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RightThighBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve PitchToPitchCorrectionCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchCorrectionSpringFrequency;
    
    UCreature_RiderComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void OnMountMovementStateChanged(UCreature_MountComponent* MountComponent, EMountMovementState PrevMovementState);
    
    UFUNCTION(BlueprintCallable)
    void OnCreatureReactionQueued(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent);
    
public:
    UFUNCTION(BlueprintCallable)
    void InterruptDismount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACreatureMountHandler* GetMountHandler() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACreature_Character* GetCreatureCharacter() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableHandIK();
    
    UFUNCTION(BlueprintCallable)
    void DisableHandIK();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateRiderComponent();
    
    UFUNCTION(BlueprintCallable)
    void ActivateRiderComponent(ACreatureMountHandler* InMountHandler, const bool bEnableHandIK);
    
};

