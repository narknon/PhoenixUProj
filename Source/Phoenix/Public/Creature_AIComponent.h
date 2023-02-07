#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "MunitionImpactData.h"
#include "CreatureLookAtBehavior.h"
#include "ECreatureAIState.h"
#include "ECreatureFleeFlyingOption.h"
#include "ECreatureIdleOverrideState.h"
#include "ECreatureMovementSpeed.h"
#include "ECreaturePathEndMode.h"
#include "ECreatureStance.h"
#include "ECreatureStoppingMode.h"
#include "NPC_Component.h"
#include "Templates/SubclassOf.h"
#include "Creature_AIComponent.generated.h"

class AActor;
class ACreaturePerceptionVolume;
class ACreatureTetherVolume;
class ACreature_Character;
class ACreature_Controller;
class APathNode;
class UAIPerceptionComponent;
class UAblAbility;
class UBlackboardComponent;
class UCreatureSpawnSlotComponent;
class UCreature_NurtureComponent;
class UInteractionArchitectAsset;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UCreature_AIComponent : public UNPC_Component {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* IdleInteractionAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TetherRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleeRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleeRunDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleeJogDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleeWalkDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleePathingDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleeScatterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FleeHerdRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* FleeDestinationOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFadeWhenFleeing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReactionInstigatorTagTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureFleeFlyingOption FleeFlyingOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFleeConstrainedByTether;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureMovementSpeed MaximumFleeMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ApproachRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnApproachRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TrotApproachRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RunApproachRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureStance InteractStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer FeedAnimLookupTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PettingAnimLookupTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PettingBrushAttachRelativeBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartWithRestIdleBehaviorChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartWithRestIdleBehaviorAtNightChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartWithForageIdleBehaviorChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ExploreRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ExploreRangeFromHerdLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinExploreWaitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxExploreWaitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExploreBehaviorLoopsMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExploreBehaviorLoopsMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTurnAnticipation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ForageRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ForageBehaviorLoopsMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ForageBehaviorLoopsMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ForageLookAroundTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanForage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GroomOrLookAroundConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GroomConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RestBehaviorLoopsMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RestBehaviorLoopsMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlightPreferredThresholdDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldFlyOutOfWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CirclingConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CirclingWhenWildConsiderationBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinCirclingHeightAboveGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCirclingHeightAboveGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinCirclingRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCirclingRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinCirclingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCirclingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanUsePerches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerchingConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerchingWhenWildConsiderationBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPerchingSearchRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPerchingSearchRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPerchingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPerchingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPerchingConstrainedByTether;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Laziness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNocturnal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanUseHerding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialHerdDetectionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanHerdSleep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanHerdFlee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D NewHerdLocationRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanGraze;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrazingMinRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrazingMaxRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StationaryGrazingDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RelaxStandingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RelaxSittingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RelaxLyingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RelaxSleepingTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelaxStandingConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelaxSittingConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelaxLyingConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelaxSleepingConsiderationMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ECreatureStance> PregnancyStances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NurtureInteractCloseRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NurtureInteractRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NurtureInteractRangeHighHappinessMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D HappinessThresholds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NurtureInteractGreetTimeInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStationaryForNurtureInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatMaxDistanceFromTether;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UInteractionArchitectAsset> AdditionalReactionAbilies_Aggressive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreatureSpawnSlotComponent* CurrentCreatureSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureLookAtBehavior LookAtBehavior;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBlackboardComponent* BlackboardComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreature_Character* CreatureCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreature_Controller* CreatureController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCreature_NurtureComponent* NurtureComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CustomAbilityClass;
    
public:
    UCreature_AIComponent();
    UFUNCTION(BlueprintCallable)
    void TryEnterScheduledEntityMode();
    
    UFUNCTION(BlueprintCallable)
    void TeamChanged();
    
    UFUNCTION(BlueprintCallable)
    void StartFollowPathBehavior(APathNode* InPathNode);
    
    UFUNCTION(BlueprintCallable)
    void SetToWalkMovementSpeed();
    
    UFUNCTION(BlueprintCallable)
    void SetToSprintMovementSpeed();
    
    UFUNCTION(BlueprintCallable)
    void SetToMovementSpeedFloat(float InSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetToMovementSpeed(ECreatureMovementSpeed MovementSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetToJogMovementSpeed();
    
    UFUNCTION(BlueprintCallable)
    void SetTetherVolume(ACreatureTetherVolume* InTetherVolume);
    
    UFUNCTION(BlueprintCallable)
    void SetStoppingMode(ECreatureStoppingMode StoppingMode);
    
    UFUNCTION(BlueprintCallable)
    void SetPathEndMode(ECreaturePathEndMode PathEndMode);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractionTime(AActor* InTargetActor);
    
    UFUNCTION(BlueprintCallable)
    void SetIdleOverrideState(ECreatureIdleOverrideState InNewState);
    
    UFUNCTION(BlueprintCallable)
    void SetFocusActorBlackboardState(AActor* FocusActor);
    
    UFUNCTION(BlueprintCallable)
    void SetDesiredCreatureStance(ECreatureStance InNewStance);
    
    UFUNCTION(BlueprintCallable)
    void SetAIState(ECreatureAIState InNewState);
    
    UFUNCTION(BlueprintCallable)
    void RemovePerceptionVolume(ACreaturePerceptionVolume* InPerceptionVolume);
    
    UFUNCTION(BlueprintCallable)
    void RandomizeApproachRadius();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnObjectStateChange(const UObject* InCaller, uint8 InInteractiveAction);
    
    UFUNCTION(BlueprintCallable)
    void OnMunitionImpactDamage(const UObject* InCaller, const FMunitionImpactData& InImpactData);
    
    UFUNCTION(BlueprintCallable)
    void OnCreatureDied();
    
    UFUNCTION(BlueprintCallable)
    void OnAIStateComplete();
    
    UFUNCTION(BlueprintCallable)
    ACreatureTetherVolume* GetTetherVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAIPerceptionComponent* GetPerceptionComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECreaturePathEndMode GetPathEndMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECreatureIdleOverrideState GetIdleOverrideState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UAblAbility> GetCustomAbilityClass() const;
    
    UFUNCTION(BlueprintCallable)
    float GetCurrentApproachRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UBlackboardComponent* GetBlackboard() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECreatureMovementSpeed GetBestSpeedToReachLocation(FVector InLocation, float InTimeToReach) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECreatureAIState GetAIState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void FindPettingBrushInitialAttachment(const FGameplayTagContainer& InAnimationVariationTagContainer, FVector& OutRelativeLocation, FRotator& OutRotation, FVector& OutScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    FTransform FindPettingBrushAttachmentRelativeTransform() const;
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteAbilityFromAsset(UInteractionArchitectAsset* InArchitectAsset);
    
    UFUNCTION(BlueprintCallable)
    void EnableCreaturePerception();
    
    UFUNCTION(BlueprintCallable)
    void DisableCreaturePerception(bool bForgetPreviousStimuli, bool bLoseAwareness);
    
    UFUNCTION(BlueprintCallable)
    void AddPerceptionVolume(ACreaturePerceptionVolume* InPerceptionVolume);
    
};

