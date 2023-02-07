#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_DoesPathExist.h"
#include "Navigation/PathFollowingComponent.h"
#include "QueueReactionParams.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "CharacterShutdownProvider_Interface.h"
#include "EEnemyAIAction.h"
#include "EEnemyAIAnimState.h"
#include "EEnemyAIState.h"
#include "EEnemy_Ability.h"
#include "EEnemy_AnimMainState.h"
#include "EEnemy_BBKey.h"
#include "EEnemy_InitTreeTimeoutAction.h"
#include "EEnemy_ParryButtonPressed.h"
#include "EEnemy_TargetType.h"
#include "ENPC_AbilityChannel.h"
#include "ENPC_CrouchContext.h"
#include "ENPC_Mobility.h"
#include "ENPC_MoveDataState.h"
#include "ENPC_SidekickUpdateState.h"
#include "ENPC_Spawn.h"
#include "ENPC_SpawnState.h"
#include "ENPC_TargetAwareState.h"
#include "ENPC_Tether.h"
#include "ENPC_WaterResponse.h"
#include "EnemyAIActionDoneDelegateDelegate.h"
#include "Enemy_LimitAttackOnTargetData.h"
#include "Enemy_ParryParamData.h"
#include "FinisherData.h"
#include "FinisherRequirementData.h"
#include "JumpSplineDoneDelegate.h"
#include "NPCAudioStateHeartbeatDelegate.h"
#include "NPCCharacterLoadedDelegateDelegate.h"
#include "NPCCharacterSpawnFinishedDelegateDelegate.h"
#include "NPCEventDelegateDelegate.h"
#include "NPCMobilityChangedDelegate.h"
#include "NPCStateChangeDelegateDelegate.h"
#include "NPC_AbilityChannel.h"
#include "NPC_AbilityChannelMap.h"
#include "NPC_ActionParams.h"
#include "NPC_AnimEventDelegateDelegate.h"
#include "NPC_JumpSplineData.h"
#include "NPC_LosingTarget.h"
#include "NPC_MobilityDataContainer.h"
#include "NPC_MobilityTransition.h"
#include "NPC_MobilityUberData.h"
#include "NPC_NavPath.h"
#include "NPC_SpawnData.h"
#include "NPC_SpawnLocationMap.h"
#include "NPC_TurnAssistDataContainer.h"
#include "NpcTimers.h"
#include "ParryWindowBeginEventDelegate.h"
#include "ParryWindowEndEventDelegate.h"
#include "ResurrectionFinishedDelegate.h"
#include "Templates/SubclassOf.h"
#include "NPC_Component.generated.h"

class AAIController;
class AActor;
class ACharacter;
class ANPC_Character;
class ANPC_Controller;
class ANPC_Spline;
class UAblAbility;
class UAblAbilityComponent;
class UAblReactionAbility;
class UAblReactionComponent;
class UAblReactionData;
class UAmbulatory_MovementComponent;
class UAnimInstance;
class UAnimationArchitectComponent;
class UBehaviorTreeComponent;
class UBlackboardComponent;
class UCapsuleComponent;
class UCurveFloat;
class UCustomizableCharacterComponent;
class UDynamicBranchComponent;
class UInteractionArchitectAsset;
class UMeshComponent;
class UNPC_AbilityTaskScratchPad;
class UNPC_AnimInstance;
class UNPC_MobilityDataContainerAsset;
class UNPC_PerceptionChoice;
class UNPC_ReactionComponent;
class UNavigationQueryFilter;
class URagdollControlComponent;
class USkeletalMeshComponent;
class USpellToolRecord;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNPC_Component : public UActorComponent, public ICharacterShutdownProvider_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* DefaultMunitionInteractionArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAnimationTickOptimization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableShutdownOptimization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootprintSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSidekick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowBackLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_SpawnLocationMap> SpawnLocationMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Spawn SpawnType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerceptionCanInterruptSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* SpawnInteractionArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_SpawnData> SpawnList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnCollisionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnCollisionImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnCollisionScaledForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_AbilityChannelMap> AbilityChannelMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_AbilityChannel DefaultChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_AbilityChannel> AbilityChannelList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> IdleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> WanderIdleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> SpawnStartAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveStopAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveStartAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MovePivotAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> SecondaryAttackAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> HealAttackAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ReparoAttackAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpSplineAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CustomSpellAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> NeutralEmotionAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> FollowSplineAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> FollowSplineIdleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblReactionAbility> WoundedKneelAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblReactionAbility> DazedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblReactionAbility> DeadAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DisillusionmentAbilityEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DisillusionmentAbilityExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIdleTimeoutFailsafe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* HealSpellToolRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* ReparoSpellToolRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* CustomSpellToolRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* DisillusionmentSpellToolRecord;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_TurnAssistDataContainer> TurnAssistDataContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_MobilityUberData> MobilityUberDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_MobilityTransition> MobilityTransitionArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UNPC_MobilityDataContainerAsset*> MobilityDataContainerAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_MobilityDataContainer> MobilityDataContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegisterAsTargetSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNPC_PerceptionChoice* PerceptionChoice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomizeScaleOnSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OppositeDirectionFleeValidDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnterOnFireState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseOnFireStateBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBroadcastAudioHeartbeat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioHeartbeatDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoDirectionAvoidance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepulsorRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepulsorRadiusCushionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepulsorDetectionRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResolveBlockedAllowableAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDirectionFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DirectionFilterRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DirectionFilterRateMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DirectionFilterRateMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DirectionAvoidanceInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvoidanceSlowdownScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag MoveTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag MoveStopTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag MoveStartTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag MovePivotTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovePivotMinAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverrideNavRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavFitRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavFitVerticalRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavFitMoveTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavReachableDownRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavReachableUpRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NavReachableRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_WaterResponse WaterResponse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LOSRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlertUIRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TASSenseHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DeadGameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer NPCTypeTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_LosingTarget> LosingTargetList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseNavigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNPC_AbilityTaskScratchPad* AbilityScratchPad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGlobalVulnerability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseExpliciteProtegoStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProtegoStaysUpWhileAttacking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoCooldownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoBrokeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoWaitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoOnOffEffectAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VulnerableAbilities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_ParryParamData ParryParamData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_LimitAttackOnTargetData LimitAttackOnTargetParamData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHeadTrackToAttackTarget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCAudioStateHeartbeat NPCAudioStateHeartbeatDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCEventDelegate NPCEventDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCMobilityChanged NPCMobilityChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCCharacterLoadedDelegate NPCCharacterLoadedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_AnimEventDelegate NPC_AnimEventDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCCharacterSpawnFinishedDelegate CharacterSpawnFinishedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FParryWindowBeginEvent OnParryWindowBeginDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FParryWindowEndEvent OnParryWindowEndDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResurrectionFinished OnResurrectionFinished;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCStateChangeDelegate OnStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyAIActionDoneDelegate ActionDoneDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReactionParrySuccessTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReactionParrySuccessTimeDilationDuration;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URagdollControlComponent* RagdollControlComp;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> WanderActorOwner;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> WanderActorFollower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ANPC_Controller* UpdateNPCControllerPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBlackboardComponent* m_pBlackboardComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDynamicBranchComponent* DynamicBranchComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNPC_ReactionComponent* NPCReactionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAmbulatory_MovementComponent* AmbulatoryMoveComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CCComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationArchitectComponent* AAComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* AbilityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBehaviorTreeComponent* BehaviorTreeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIState DefaultState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetLockedStateForScheduledEntityMode;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FJumpSplineDone JumpSplineDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> EmoDefaultAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCriticalFinisherAllowTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> TransformIntoCreature;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFinisherRequirementData> FinisherData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFinisherDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFinisherData DebugFinisher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNpcTimers NpcTimers;
    
public:
    UNPC_Component();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasActionASuccess(EEnemyAIAction InAction) const;
    
    UFUNCTION(BlueprintCallable)
    bool UpdateTetheredLoc(FVector& OutLoc, bool& OutDone);
    
    UFUNCTION(BlueprintCallable)
    void UnchainAction(EEnemyAIAction ChainFromAction);
    
    UFUNCTION(BlueprintCallable)
    bool TreeWaitUpdate(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    FVector TetheredWanderLocation();
    
    UFUNCTION(BlueprintCallable)
    void StopSpeedScaleAdjust();
    
    UFUNCTION(BlueprintCallable)
    void StopMove();
    
    UFUNCTION(BlueprintCallable)
    void StopActionOnUpdate(EEnemyAIAction InAction);
    
    UFUNCTION(BlueprintCallable)
    void StopAction(EEnemyAIAction InAction, bool bSuccess, bool bTimeout);
    
    UFUNCTION(BlueprintCallable)
    void StartupAbility();
    
    UFUNCTION(BlueprintCallable)
    void StartSpeedScaleAdjust(float InScale, float DurationSeconds);
    
    UFUNCTION(BlueprintCallable)
    void StartDynamicBranch(EEnemy_Ability InAbility, EEnemy_Ability InNextAbility, bool bImmediate);
    
    UFUNCTION(BlueprintCallable)
    void StartCustomPause(bool bCleanupWhenCustomAbilityFinished);
    
    UFUNCTION(BlueprintCallable)
    bool StartAction(EEnemyAIAction InAction, float Timeout);
    
    UFUNCTION(BlueprintCallable)
    bool SidekickUpdateStateUpdate(ENPC_SidekickUpdateState InUpdateState, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void SetWanderStartLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetSightedEnable(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetLocationTurnInPlace(FVector InTargetLoc_TurnInPlace);
    
    UFUNCTION(BlueprintCallable)
    void SetTarget(AActor* pTarget);
    
    UFUNCTION(BlueprintCallable)
    void SetStealthContext();
    
    UFUNCTION(BlueprintCallable)
    void SetSpeedScale(float InScale);
    
    UFUNCTION(BlueprintCallable)
    void SetSpeedChooserScale(float InScale);
    
    UFUNCTION(BlueprintCallable)
    void SetSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnAnimOffset(float InOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    void SetOverrideMobility(ENPC_Mobility InMobility);
    
    UFUNCTION(BlueprintCallable)
    void SetOnStairs();
    
    UFUNCTION(BlueprintCallable)
    void SetOnSlope();
    
    UFUNCTION(BlueprintCallable)
    void SetOnFire();
    
    UFUNCTION(BlueprintCallable)
    void SetMoveGoal(FVector InGoal, bool bNavReachable);
    
    UFUNCTION(BlueprintCallable)
    void SetJumpSplineData(const FNPC_JumpSplineData& InData);
    
    UFUNCTION(BlueprintCallable)
    void SetJumpSpline(ANPC_Spline* InSplinePtr);
    
    UFUNCTION(BlueprintCallable)
    void SetInvincibility(bool InIsInvincible);
    
    UFUNCTION(BlueprintCallable)
    void SetForcedPerceptionTarget(AActor* InTargetPtr, ENPC_TargetAwareState InTAS, float InTime);
    
    UFUNCTION(BlueprintCallable)
    void SetFleeTargetPos(FVector InPos);
    
    UFUNCTION(BlueprintCallable)
    void SetFireExtinguished();
    
    UFUNCTION(BlueprintCallable)
    void SetFinisherTagFilter(FGameplayTag InTag);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomPauseExitConditions(bool bCleanupWhenAlert, bool CleanupWhenAttack, AActor* TargetToAllow);
    
    UFUNCTION(BlueprintCallable)
    void SetCrouching();
    
    UFUNCTION(BlueprintCallable)
    void SetCrouchContextFlag(ENPC_CrouchContext CrouchContext);
    
    UFUNCTION(BlueprintCallable)
    void SetCharred();
    
    UFUNCTION(BlueprintCallable)
    void SetCharacterRootMotionScale(float RootMotionScale);
    
    UFUNCTION(BlueprintCallable)
    void SetBlackboardKey(EEnemy_BBKey InKey, bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetBlackboardFloat(const FName& InBBName, float InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetBlackboardBool(const FName& InBBName, bool InValue);
    
    UFUNCTION(BlueprintCallable)
    void SetBlackboard(UBlackboardComponent* pBlackboardComp);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackCustomFlag(bool FlagIsSet);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimState(EEnemyAIAnimState InAnimState);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimSpawnState(ENPC_SpawnState InSpawnState);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimMainState(EEnemy_AnimMainState InAnimState);
    
    UFUNCTION(BlueprintCallable)
    void SetActionParams(FNPC_ActionParams InParams);
    
    UFUNCTION(BlueprintCallable)
    void SetAction(EEnemyAIAction InAction, bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void SetAbilityScratchpadVelocity(FVector InVelocity);
    
    UFUNCTION(BlueprintCallable)
    void SetAbilityActive(EEnemy_Ability InState, bool bActive);
    
    UFUNCTION(BlueprintCallable)
    int32 PickRandomPath(const AAIController* AIOwner, TArray<FVector> Targets, float TopPercent, TEnumAsByte<EPathExistanceQueryType::Type> PathQueryType, TSubclassOf<UNavigationQueryFilter> FilterClass, bool AllowPartialPaths, FVector& outTarget);
    
    UFUNCTION(BlueprintCallable)
    bool PathExists(const AAIController* AIOwner, FVector Target, TEnumAsByte<EPathExistanceQueryType::Type> PathQueryType, TSubclassOf<UNavigationQueryFilter> FilterClass, bool AllowPartialPaths);
    
    UFUNCTION(BlueprintCallable)
    void ParryEvent(EEnemy_ParryButtonPressed InButtonPressed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStationOnFinishedExit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStationOnFinishedEnter();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnReactionReceived(const FQueueReactionParams& ReactionParams, UAblReactionComponent* ReactionComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnReactionQueued(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent);
    
    UFUNCTION(BlueprintCallable)
    void OnReactionEnd(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnMovementModeChange(ACharacter* Character, TEnumAsByte<EMovementMode> PrevMovementMode, uint8 PreviousCustomMode);
    
    UFUNCTION(BlueprintCallable)
    void OnLoadComplete(AActor* LoadedActor);
    
    UFUNCTION(BlueprintCallable)
    void OnExitAliveVolume(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void OnEnterKillVolume(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void OnDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void NPCRemoveFromManager(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void NPCAddToManager(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool NeedsStayInVolumeConstrain(const FVector& InLoc) const;
    
    UFUNCTION(BlueprintCallable)
    bool MoveToOnFire(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    bool MoveToLocation(FVector Loc, UCurveFloat* CurveFloatPtr, float InterpSpeed, float DeltaTime, bool bStopOnOverlap);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EPathFollowingRequestResult::Type> MoveTo(const FVector Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPath);
    
    UFUNCTION(BlueprintCallable)
    void Kill();
    
    UFUNCTION(BlueprintCallable)
    void K2_SetTargetableByPlayer(bool bTargetableByPlayer);
    
    UFUNCTION(BlueprintCallable)
    void JumpSplineStart();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsVulnerable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetSightedEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSwimming() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStationary() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsSpawnFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReactionActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnStairs() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnSlope() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnFire() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNearDeathKneeling() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMoveDone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJumpSplineDone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInvincible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInStealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInStation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInjured() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFlying() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDead() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCrouching() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCompanion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCharred() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBlind() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionDone(EEnemyAIAction InAction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionActive(EEnemyAIAction InAction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAbilityVulnerable(EEnemy_Ability InAbility) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAbilitySupported(EEnemy_Ability InAbility) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAbilityActive(EEnemy_Ability InState) const;
    
    UFUNCTION(BlueprintCallable)
    FGameplayTagContainer InsertIATagsToSpawnData(ENPC_Spawn InSpawnType, FGameplayTagContainer InTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void InitTreeWait(const FGameplayTag& TreeTag, const TArray<EEnemy_Ability>& InAbilityList, float Timeout, EEnemy_InitTreeTimeoutAction TimeoutAction);
    
    UFUNCTION(BlueprintCallable)
    void InitTetheredLoc(float InTetherDist, const FVector& InStartVec, bool bUseStartVec, float InMaxAngle, int32 InDivisions, bool bInApplyTether, ENPC_Tether InTetherType, float randomDistFloor, float randomDistCeiling);
    
    UFUNCTION(BlueprintCallable)
    bool InitMoveToOnFire();
    
    UFUNCTION(BlueprintCallable)
    bool InitMoveToLocation(FVector DestinationLoc, float Timeout, ENPC_Mobility InMobility, bool bOverrideMobility);
    
    UFUNCTION(BlueprintCallable)
    bool InitMoveToFleePos(FVector InPos, float Timeout);
    
    UFUNCTION(BlueprintCallable)
    void InitMoveData(ENPC_MoveDataState InState, AActor* TargetPtr, float Timeout);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSightedTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasFinisherWithRunningRequirementsMet(AActor* Attacker) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetYaw() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetWanderStartLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTreeWaitResult() const;
    
    UFUNCTION(BlueprintCallable)
    FVector GetTetheredLoc(float InDist, const FVector& InStartVec, bool bUseStartVec, float InMaxAngle, int32 InDivisions, bool bInApplyTether, ENPC_Tether InTetherType, float randomDistFloor, float randomDistCeiling);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEnemy_TargetType GetTargetType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTargetLookatApha() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget() const;
    
    UFUNCTION(BlueprintCallable)
    float GetSpeedScale();
    
    UFUNCTION(BlueprintCallable)
    float GetSpeedChooserScale();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENPC_SidekickUpdateState GetSidekickUpdateState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetScale() const;
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UAblAbility> GetPlayerCriticalFinisherAbility(FGameplayTagContainer& MunitionsTags);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UAblAbility> GetPlayerCriticalDamageAbility(FGameplayTagContainer& MunitionsTags);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPerceptionSuspended() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPerceptionEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENPC_Mobility GetOverrideMobility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetOnGround() const;
    
    UFUNCTION(BlueprintCallable)
    UNPC_AnimInstance* GetNPCAnimInstance();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetMyLoc() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetMyGroundLoc() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMoveToLocationSuccess() const;
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EPathFollowingRequestResult::Type> GetMoveToLocationResult();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMoveTolerance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMoveToDone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMoveDataSuccess() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENPC_Mobility GetMobility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetMeshComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENPC_TargetAwareState GetKilledTAS() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetForcedPerceptionTarget();
    
    UFUNCTION(BlueprintCallable)
    FVector GetFleeTargetPos();
    
    UFUNCTION(BlueprintCallable)
    FVector GetFleeDistLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEnemyAIAction GetChainedAction(EEnemyAIAction InAction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCapsuleRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCapsuleHalfHeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAUXRecoverLoc() const;
    
    UFUNCTION(BlueprintCallable)
    EEnemyAIAnimState GetAnimState();
    
    UFUNCTION(BlueprintCallable)
    ENPC_SpawnState GetAnimSpawnState();
    
    UFUNCTION(BlueprintCallable)
    EEnemy_AnimMainState GetAnimMainState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimInstance* GetAnimInstance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEnemy_Ability GetActiveAbility() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAction(EEnemyAIAction InAction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UNPC_AbilityTaskScratchPad* GetAbilityScratchpad() const;
    
    UFUNCTION(BlueprintCallable)
    void ForcePerceptionUpdate();
    
    UFUNCTION(BlueprintCallable)
    void FinishReactionParrySuccessTimeDilation();
    
    UFUNCTION(BlueprintCallable)
    FVector FindValidLocation(FVector InPos);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteAbility(TSubclassOf<UAblAbility> InAbilityPtr, ENPC_AbilityChannel InChannel);
    
    UFUNCTION(BlueprintCallable)
    void EnterTree(const FGameplayTag& TreeTag, bool InAbortMove);
    
    UFUNCTION(BlueprintCallable)
    void EndCustomPause();
    
    UFUNCTION(BlueprintCallable)
    void EnablePerception(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void EnableAbilityChannel(ENPC_AbilityChannel InChannel, bool bInEnable);
    
    UFUNCTION(BlueprintCallable)
    bool CriticalFinisherAllowTimeDilation();
    
    UFUNCTION(BlueprintCallable)
    static FNPC_NavPath CreateNavPath(AAIController* InControllerPtr, const FVector& InStartLoc, const FVector& InEndLoc, float InToleranceRadius);
    
    UFUNCTION(BlueprintCallable)
    void ClearStealthContext();
    
    UFUNCTION(BlueprintCallable)
    void ClearCrouchContextFlag(ENPC_CrouchContext CrouchContext);
    
    UFUNCTION(BlueprintCallable)
    void ChainAction(EEnemyAIAction ChainFromAction, EEnemyAIAction ChainToAction);
    
    UFUNCTION(BlueprintCallable)
    float CalcFleeMoveToLocationTime(FVector InDestination);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastNPC_AnimEvent(FName InName);
    
    UFUNCTION(BlueprintCallable)
    AActor* AttemptToFindUniqueOwnerForFollower(TSubclassOf<ANPC_Character> OwnerClass, ANPC_Character* InFollower, float FindDistance);
    
    UFUNCTION(BlueprintCallable)
    AActor* AttemptToFindPackOwnerForFollower(ANPC_Character* InFollower, float FindDistance);
    
    UFUNCTION(BlueprintCallable)
    void ActionUpdate(EEnemyAIAction InAction, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void AbortAction(EEnemyAIAction InAction);
    
    
    // Fix for true pure virtual functions not being implemented
};

