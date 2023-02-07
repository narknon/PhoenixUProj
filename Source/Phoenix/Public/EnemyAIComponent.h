#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "ActorHitDelegateDelegate.h"
#include "AlertStateChangedDelegateDelegate.h"
#include "AttackBeginDelegateDelegate.h"
#include "AttackCollisionType.h"
#include "AttackEndDelegateDelegate.h"
#include "ClimbSettings.h"
#include "EActor_LoadDBProcessingType.h"
#include "ECreatureStance.h"
#include "EEEnemyAISizeCategory.h"
#include "EEnemyAIAttackState.h"
#include "EEnemy_Ability.h"
#include "EEnemy_AbilityEvent.h"
#include "EEnemy_AttackLocSource.h"
#include "EEnemy_AttackResetSource.h"
#include "EEnemy_AttackSource.h"
#include "EEnemy_AttackUpdateState.h"
#include "EEnemy_AttackingState.h"
#include "EEnemy_ProtegoLevel.h"
#include "ENPC_HitDirection.h"
#include "ENPC_Mobility.h"
#include "ENPC_QBUpdate.h"
#include "ENPC_Spawn.h"
#include "ENPC_TargetAwareState.h"
#include "EnemyAIArrivedDelegateDelegate.h"
#include "EnemyAIWeaponsLoadedDelegateDelegate.h"
#include "EnemyEvadeData.h"
#include "EnemyGameEventData.h"
#include "EnemyVulnerableData.h"
#include "Enemy_AccuracyData.h"
#include "Enemy_AlertData.h"
#include "Enemy_ApparateData.h"
#include "Enemy_ApparateToData.h"
#include "Enemy_AttackLocUpdateData.h"
#include "Enemy_EnergyData.h"
#include "Enemy_IdleBreak.h"
#include "Enemy_IdleData.h"
#include "Enemy_MeleeAttackOverlapData.h"
#include "Enemy_MoveStopData.h"
#include "Enemy_NextDecisionWait.h"
#include "Enemy_NextMoveWait.h"
#include "Enemy_Shuffle.h"
#include "Enemy_ShuffleData.h"
#include "Enemy_Taunt.h"
#include "Enemy_TurnInPlaceData.h"
#include "LadderSettings.h"
#include "MaterialParameterSetter.h"
#include "NPC_Component.h"
#include "NPC_GameChangerState.h"
#include "NPC_PerceptionInfo.h"
#include "NPC_ShowUI.h"
#include "OnAlertSenseChangedDelegateDelegate.h"
#include "OnDeadDelegateDelegate.h"
#include "OnDeathDelegateDelegate.h"
#include "OnDodgeDelegateDelegate.h"
#include "OnSpawnFinishedDelegateDelegate.h"
#include "RipApartFinisherData.h"
#include "SlideSettings.h"
#include "SpawnEndDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "ThreatStateChangedDelegateDelegate.h"
#include "VaultSettings.h"
#include "EnemyAIComponent.generated.h"

class AActor;
class AEnemyAIWeapon;
class ANPC_Character;
class APathNode;
class ASpellCasterTool;
class ASpellTool;
class UAblAbility;
class UAblReactionComponent;
class UAblReactionData;
class UBehaviorTree;
class UCurveFloat;
class UEnemyAIAttackData;
class UEnemyAIPathCheckPropertyData;
class UEnemyAISpawnData;
class UEnemyCorruptionData;
class UEnemyHiddenTeleportAttackComponent;
class UEnemy_AnimInstance;
class UEnemy_AttackComponent;
class UEnemy_InstanceQBUpdateData;
class UEnemy_QBUpdateData;
class UEnemy_TargetSenseAsset;
class UEnemy_WeaponComponent;
class UInteractionArchitectAsset;
class ULadderNavLinkComponent;
class USlideNavLinkComponent;
class USpellToolRecord;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyAIComponent : public UNPC_Component {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_damageDestructables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveMaxAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAngleFromCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TooCloseToTargetDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bImmuneToCCIncapacition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRipApartFinisherData RipApartFinisherData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProximityAttackDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProximityMoveDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProximityAttackDistCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProximityAttackMinTimeSinceLastAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CounterAttackWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CounterAttackCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttackDisable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttackWithoutRestrictions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysMyTurn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNoAttackExecuteCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNoAttackSelectCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysInRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysAccurate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllAttacksRequireTickets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStationaryAttackAllowedOutOfRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttackExitAsSoonAsFired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreCorridors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_AttackLocUpdateData AttackLocUpdateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* AttackSplitBehaviorTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* AttackCounterBehaviorTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RetaliatePauseTicketRecoverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeammateLOSCorridorHalfWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeammateLOSUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TeammateLOSRequireForNPCAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAbruptDestinationChangeCheck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AbruptDestinationChangeAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatLocSearchAngleWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatFootprintSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UEnemy_QBUpdateData*> QBUpdateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UEnemy_InstanceQBUpdateData*> QBInstanceUpdateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyAIPathCheckPropertyData* PathCheckPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEEnemyAISizeCategory SizeCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TurnInPlaceData TurnInPlaceData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableEnergyDrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_EnergyData> EnergyDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableBreaks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakIntervalBetween;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableBreakIntervalDecay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakIntervalBetweenDeviation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreakDurationDeviation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> BecomeAlertAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> AlertFaceAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> AlertWaitAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> LoseAlertAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> BecomeAwareAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> LoseAwareAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> TurnInPlaceAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> IdleBreakAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ShuffleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> TauntAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateOutAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateWaitAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateInAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> WeaponEquipAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> WeaponStoreAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> WeaponPickupAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> WeaponLostAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> WeaponRecoveredAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpDownAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpStraightAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpSoftLandAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpLandPT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DeathTauntAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> FlourishAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> FlyingAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> StartDrainedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DrainedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> StopDrainedAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> InvestigateStartAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> InvestigateMoveAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> InvestigateIdleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> InvestigateStopAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ReflectionIdleAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TargetAwareState ForceTargetAwareState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForceTargetAwareStateTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTASForceIntoAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTASEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayBecomeAware;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayBecomeAwareChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeammatesPlayBecomeAwareChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayLoseAware;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetDesiredDirectionInAlertFace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowAwareTurnAround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClimbSettings ClimbSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLadderSettings LadderSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlideSettings SlideSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVaultSettings VaultSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequireStationaryForIdleChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_IdleData IdleData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_NextDecisionWait> NextDecisionWaitList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_NextMoveWait> NextMoveWaitList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_MoveStopData> MoveStopDataList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCreatureMoveToStopPrediction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCreatureMoveToStopBranching;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateMobilityInBecomeOrLoseAware;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Mobility MobilityForAlarmedInvestigate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_IdleData TauntData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_Taunt> TauntList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_IdleData IdleBreakData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_IdleBreak> IdleBreakList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_ShuffleData ShuffleIdleData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_IdleData ShuffleData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ShuffleSupportedDirections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ShuffleDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_Shuffle> ShuffleList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowShuffleWhenTooClose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowShuffleWithoutWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EvadeBeingTargetedThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChanceToEvade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyEvadeData> EnemyEvadeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFavorEvade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealAmountPerEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AEnemyAIWeapon>> ProtegoRequiredWeaponList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_ProtegoLevel ProtegoDefenseLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChanceToProtego;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChanceToProtegoLightAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChanceToProtegoMediumAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChanceToProtegoHeavyAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProtegoDeflectedAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlockAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DeflectBackAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DeflectToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoDeflectionTimeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeflectedAttackTimeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPowerupEligible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerupTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyVulnerableData> EnemyStrengthData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyVulnerableData> EnemyWeaknessData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyVulnerableData> EnemyAttackStrengthData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyVulnerableData> EnemyAttackWeaknessData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyGameEventData> EnemyGameEventData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* GameEvenetInteractionArchitectAssetPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBuffAllowHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBuffAllowWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisarmRespawnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* ProtegoAttackPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ProtegoAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ProtegoStartupAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProtegoAdditive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ProtegoChannelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* ProtegoInteractionArchitectAssetPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProtegoHoldTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProtegoPlayDeflection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProtegoShowShieldPulseWhenHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProtegoShowOnOffShieldEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowProtegoToInterrupAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowProtegoToInterrupReactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProtegoDeflectionChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyUseDOTReactionForCrucio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* LumosPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> LumosAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLumosAdditive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LumosChannelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanApparateIfUnreachableLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanApparateToMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanApparateToRecoverWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApparateUsingFixedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ApparateSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ApparateFixedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_ApparateData> ApparateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemy_TargetSenseAsset* LeaderTargetSenseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemy_TargetSenseAsset* CompanionTargetSenseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CompanionPerceptionMinTimeSincePlayerAttacked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> BabyNPCClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BabySpawnObjectName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_AccuracyData Accuracy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowTooCloseCounterAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowCreateAggroHideTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowApparateMoveWithInvalidMoveLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeleportMoveRangeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeleportMoveStuckRangeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageBuffMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_onGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_lastOnGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnSpellCaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnProtegoCaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellCasterSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> SpellCasterClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAttackBeginDelegate m_attackBeginDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAttackEndDelegate m_attackEndDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnEndDelegate m_spawnEndDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorHitDelegate m_actorHitDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeathDelegate m_onDeathDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeadDelegate OnDeadDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpawnFinishedDelegate m_onSpawnFinishedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyAIWeaponsLoadedDelegate m_weaponsLoadedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyAIArrivedDelegate m_arrivedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FThreatStateChangedDelegate OnThreatChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlertStateChangedDelegate m_onAlertStateChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyHiddenTeleportAttackComponent* HiddenTeleportAttackComp;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAlertSenseChangedDelegate m_onAlertSenseChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDodgeDelegate m_FOnDodgeDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KeepAwayFromTargetDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseFootMatching;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApparateAfterReactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_ApparateToData ApparateAfterReactionsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyCorruptionData* AggroCorruption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UEnemyCorruptionData* AggroCorruptionInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialParameterSetter Corruption;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer EscapeExceptionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ANPC_Character* GameChangerForm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CustTargetPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemy_AttackComponent* AttackComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemy_WeaponComponent* WeaponComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CurrentClimbAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CurrentJumpToClimbAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    ULadderNavLinkComponent* CurrentLadder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USlideNavLinkComponent* CurrentSlide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> CurrentVaultAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> AnimagusPreloadClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAnimagusFormPreloading;
    
public:
    UEnemyAIComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasAttackParried(AActor* InVictimPtr) const;
    
    UFUNCTION(BlueprintCallable)
    bool WaitForCreatureStance(ECreatureStance InWaitForStance, bool bWaitForStationary, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    bool WaitForAbility(EEnemy_Ability InWaitForState, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void UpdateHealthRTPCCallback(AActor* InActor, float Delta, bool bIndicateHUD);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool UpdateFollowSpline(float DeltaTime);
    
public:
    UFUNCTION(BlueprintCallable)
    void UpdateFacingToLoc(FVector Loc, UCurveFloat* CurvePtr, float InterpSpeed, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void UpdateAttackLocation();
    
    UFUNCTION(BlueprintCallable)
    void UnhideActiveWeapon();
    
    UFUNCTION(BlueprintCallable)
    void TrackMeleePoints(const FVector& InMeleeLoc);
    
    UFUNCTION(BlueprintCallable)
    void ThrowWeapon();
    
    UFUNCTION(BlueprintCallable)
    void TeamChanged();
    
    UFUNCTION(BlueprintCallable)
    bool StoreWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void StopWandLinkCowerDelayed();
    
    UFUNCTION(BlueprintCallable)
    void StopProtegoSpell();
    
    UFUNCTION(BlueprintCallable)
    void StopGameChanger();
    
    UFUNCTION(BlueprintCallable)
    void StopCastSpell(USpellToolRecord* SpellToolRecord);
    
    UFUNCTION(BlueprintCallable)
    void StartProtegoSpell();
    
    UFUNCTION(BlueprintCallable)
    void StartGameChanger();
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartFollowSpline();
    
public:
    UFUNCTION(BlueprintCallable)
    bool StartAttack();
    
    UFUNCTION(BlueprintCallable)
    void StartApparateInEvent();
    
    UFUNCTION(BlueprintCallable)
    void SplineSpawnDoneEvent(AActor* InApparateActor);
    
    UFUNCTION(BlueprintCallable)
    void SplineSpawnArrivedEvent(AActor* InApparateActor, FVector InLoc);
    
    UFUNCTION(BlueprintCallable)
    AEnemyAIWeapon* SpawnWeapon(TSubclassOf<AEnemyAIWeapon> SpawnWeaponClass);
    
    UFUNCTION(BlueprintCallable)
    void SpawnLoot();
    
protected:
    UFUNCTION(BlueprintCallable)
    AActor* SpawnChild_BP(const FString& ObjectToSpawn, ENPC_Spawn InSpawnType, const FString& TeamName, FTransform SpawnTransform);
    
public:
    UFUNCTION(BlueprintCallable)
    void SpawnAnimagusForm();
    
    UFUNCTION(BlueprintCallable)
    void SetWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetWanderMode();
    
    UFUNCTION(BlueprintCallable)
    void SetUnblockableTags(FGameplayTagContainer& InOutTagContainer, UEnemyAIAttackData* attackDataPtr, bool bForceUnblockable);
    
    UFUNCTION(BlueprintCallable)
    void SetToDie(AActor* InstigatorPtr, UInteractionArchitectAsset* InMunitionDataAssetPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetTASEnabled(bool inEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetStationaryMode();
    
    UFUNCTION(BlueprintCallable)
    void SetSpellCaster(ASpellCasterTool* InSpellCaster);
    
    UFUNCTION(BlueprintCallable)
    void SetShowShieldWhenHit(bool bShowWhenHit);
    
    UFUNCTION(BlueprintCallable)
    void SetShowOnOffShieldEffects(bool bShowShieldEffects);
    
    UFUNCTION(BlueprintCallable)
    void SetShieldToAcquire(AEnemyAIWeapon* InShieldPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetShieldSpellDeflectionIfEquipped(bool bShouldDeflect);
    
    UFUNCTION(BlueprintCallable)
    void SetShield(AEnemyAIWeapon* InShieldPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetScaredMode();
    
    UFUNCTION(BlueprintCallable)
    void SetResurrectedEvent();
    
    UFUNCTION(BlueprintCallable)
    void SetPlayProtegoDeflection(bool bPlay);
    
    UFUNCTION(BlueprintCallable)
    void SetPathMode(APathNode* pPathNode);
    
    UFUNCTION(BlueprintCallable)
    static void SetParentToActors(const TArray<AActor*>& InActorList, AActor* InParent);
    
    UFUNCTION(BlueprintCallable)
    void SetNoAttackSelectCooldown(bool bNo);
    
    UFUNCTION(BlueprintCallable)
    void SetNoAttackExecuteCooldown(bool bNo);
    
    UFUNCTION(BlueprintCallable)
    void SetNewAlertUIData(FNPC_ShowUI NewShowUI);
    
    UFUNCTION(BlueprintCallable)
    void SetInAttackWindow(bool bin);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreAttackCorridors(bool bIgnore);
    
    UFUNCTION(BlueprintCallable)
    void SetGameChangerState(NPC_GameChangerState InState);
    
    UFUNCTION(BlueprintCallable)
    void SetGameChangerObjectName(const FString& inObjectName);
    
    UFUNCTION(BlueprintCallable)
    void SetGameChangerForm(ANPC_Character* inGameChangerForm);
    
    UFUNCTION(BlueprintCallable)
    void SetForceIntoAttackTAS(bool bForce);
    
    UFUNCTION(BlueprintCallable)
    void SetDestroyed();
    
    UFUNCTION(BlueprintCallable)
    void SetDeadMode();
    
    UFUNCTION(BlueprintCallable)
    void SetDeadEvent(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void SetDamagedEvent(float InAmount, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomAttackData(UEnemyAIAttackData* InCustAttackPtr, AActor* InCustTarget);
    
    UFUNCTION(BlueprintCallable)
    void SetCantMoveDuringAttack(bool disableMove);
    
    UFUNCTION(BlueprintCallable)
    void SetCanAttack(bool canAttack);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackWithoutRestrictions(bool bInWithoutRestrictions);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackMode(AActor* pTarget);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackLocation(FVector InLocation);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackingState(EEnemy_AttackingState InState);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackExitAsSoonAsFired(bool bExit);
    
    UFUNCTION(BlueprintCallable)
    void SetAttackCollisionType(AttackCollisionType InCollisionType);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimagusWolfPerceivedTarget();
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysMyTurn(bool bInAlwaysMyTurn);
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysInRange(bool bAlways);
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysAccurate(bool bAlways);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowProtegoToInterruptAttack(bool bAllowProtegoInterrupt);
    
    UFUNCTION(BlueprintCallable)
    void SetAlertMode(AActor* pTarget);
    
    UFUNCTION(BlueprintCallable)
    float SendMunitionImpact(const FHitResult& HitResult, AActor* pVictim, AActor* pOriginator, UInteractionArchitectAsset* pMunitionDataAsset, FName InMunitionImpactType, const FGameplayTagContainer& InMunitionTagContainer, bool bForceUnblockable);
    
    UFUNCTION(BlueprintCallable)
    void RotateToLoc(FVector Loc);
    
    UFUNCTION(BlueprintCallable)
    void RotateToAttack();
    
    UFUNCTION(BlueprintCallable)
    void RespawnWeapon();
    
    UFUNCTION(BlueprintCallable)
    void ResetDisengagedState();
    
    UFUNCTION(BlueprintCallable)
    void ResetAttack(EEnemy_AttackResetSource InResetSource);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseWeapon(AEnemyAIWeapon* InWeaponPtr, bool bForceDestroy, bool bSetDropVel, bool bIsThrown, bool bForceDrop);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseSpellCaster(ASpellCasterTool* InSpellCasterPtr);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseShield(AEnemyAIWeapon* InShieldPtr, bool bSetDropVel);
    
    UFUNCTION(BlueprintCallable)
    void ReactionStart(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent);
    
    UFUNCTION(BlueprintCallable)
    void PublishAttackStateToBlackboard();
    
    UFUNCTION(BlueprintCallable)
    void PreparePotentialSpawnLocations();
    
    UFUNCTION(BlueprintCallable)
    void PreloadAnimagusForm(TSoftClassPtr<AActor> AnimalForm);
    
    UFUNCTION(BlueprintCallable)
    bool PreAttack(EEnemy_AttackSource InSource);
    
    UFUNCTION(BlueprintCallable)
    void PathNodeArrival();
    
    UFUNCTION(BlueprintCallable)
    bool OverlapMeleeCapsule(AActor* InVictim, FHitResult InHitResult, ENPC_HitDirection InForceDirection, FEnemy_MeleeAttackOverlapData& OutOverlapData);
    
    UFUNCTION(BlueprintCallable)
    void OnReplicatedFormDeath();
    
    UFUNCTION(BlueprintCallable)
    void OnObjectLoaded(const FString& ObjectToLoad);
    
    UFUNCTION(BlueprintCallable)
    void OnJumpSplineDone();
    
    UFUNCTION(BlueprintCallable)
    void OnAttackDBLoaded(AActor* LoadActor, TEnumAsByte<EActor_LoadDBProcessingType> LoadType);
    
    UFUNCTION(BlueprintCallable)
    void OnAnimagusFormTransformed();
    
    UFUNCTION(BlueprintCallable)
    void OnAnimagusFormTimeout();
    
    UFUNCTION(BlueprintCallable)
    void OnAnimagusFormDeath();
    
    UFUNCTION(BlueprintCallable)
    void OnAnimagusFormAvadaKedavra();
    
    UFUNCTION(BlueprintCallable)
    void OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void OnActorDamaged(AActor* InActor, AActor* InInstigator, float InDamage, const FHitResult& InHit);
    
    UFUNCTION(BlueprintCallable)
    bool MoveToAttackRunTo(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    bool MoveToAttackLocation(FVector DestinationLoc, UCurveFloat* CurveFloatPtr, float InterpSpeed, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void LogBehaviorTree(FName TaskName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingNavLink() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRequiredWeaponStored(const UEnemyAIAttackData* AttackPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFacingToLoc(FVector Loc, float MinAngle) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsCharacterDisengaged();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAttacking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool InRangeToLoc(FVector TestLoc, FVector Loc, float MinRange, float MaxRange, float Tolerance, bool bAllowIfTooClose, float& OutDistFromRange) const;
    
    UFUNCTION(BlueprintCallable)
    void InitWaitForCreatureStance(ECreatureStance InWaitForStance, bool bWaitForStationary, float Timeout);
    
    UFUNCTION(BlueprintCallable)
    void InitWaitForAbility(float Timeout);
    
    UFUNCTION(BlueprintCallable)
    bool InitMoveToAttackRunTo(float Timeout);
    
    UFUNCTION(BlueprintCallable)
    bool InitMoveToAttackLocation(FVector DestinationLoc, float Timeout);
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitFollowSpline();
    
public:
    UFUNCTION(BlueprintCallable)
    void HideProtegoSpell(bool bInHide);
    
    UFUNCTION(BlueprintCallable)
    void HideActiveWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasStoredWeapon() const;
    
    UFUNCTION(BlueprintCallable)
    void HandleSpellSuccess(AActor* Target, const ASpellTool* Spell, FName SpellType);
    
    UFUNCTION(BlueprintCallable)
    bool HandleOnActorHit(AActor* pOtherActor, const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable)
    void HandleOnActorEndHit(AActor* pOtherActor);
    
    UFUNCTION(BlueprintCallable)
    void HandleAttackDone();
    
    UFUNCTION(BlueprintCallable)
    void HandleAbilityAnimEvent(EEnemy_AbilityEvent inAnimEvent);
    
    UFUNCTION(BlueprintCallable)
    bool HandleAbilityActorHit(AActor* InOtherActor, const FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable)
    AEnemyAIWeapon* GetWeaponToAcquire();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWeaponRequiredPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEnemyAIWeapon* GetWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUnblockable(AActor* InVictimPtr, bool bForceUnblockable) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEnemyAIWeapon* GetTransientWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASpellCasterTool* GetSpellCaster() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetSpawnLoc() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEnemyAISpawnData* GetSpawnData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetSizeCategoryString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEEnemyAISizeCategory GetSizeCategory() const;
    
    UFUNCTION(BlueprintCallable)
    UEnemy_QBUpdateData* GetQBUpdateData(EEnemy_AttackLocSource InSource);
    
    UFUNCTION(BlueprintCallable)
    EEnemy_ProtegoLevel GetProtegoSpellLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APathNode* GetPathNode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEnemy_InstanceQBUpdateData* GetOrCreateQBUpdateInstanceData(ENPC_QBUpdate InUpdate);
    
    UFUNCTION(BlueprintCallable)
    FNPC_PerceptionInfo GetNPCPerceptionInfo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMoveToAttackRunToSuccess() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetLastKnownTargetLoc() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsStealthAttackCurrentlyDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInAttackWindow() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    NPC_GameChangerState GetGameChangerState() const;
    
    UFUNCTION(BlueprintCallable)
    FString GetGameChangerObjectName();
    
    UFUNCTION(BlueprintCallable)
    ANPC_Character* GetGameChangerForm();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetEnemyWeaponTagContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInteractionArchitectAsset* GetEnemyWeaponDataAsset() const;
    
    UFUNCTION(BlueprintCallable)
    UEnemy_AnimInstance* GetEnemyAnimInstance();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamage(AActor* InVictimPtr, AEnemyAIWeapon* InWeaponPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCriticalHealthPercept() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanAttack() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetAttackWaitingForDesynchronization();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAttackUpdateStateSuccess() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEnemy_AttackUpdateState GetAttackUpdateState() const;
    
    UFUNCTION(BlueprintCallable)
    EEnemyAIAttackState GetAttackStateRange();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEnemyAIAttackState GetAttackState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAttackLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AttackCollisionType GetAttackCollisionType() const;
    
    UFUNCTION(BlueprintCallable)
    float GetAlertSense();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEnemy_AlertData GetAlert() const;
    
    UFUNCTION(BlueprintCallable)
    AEnemyAIWeapon* GetActiveSpawnMeteorData();
    
    UFUNCTION(BlueprintCallable)
    void ForceQBDataForceUpdate();
    
    UFUNCTION(BlueprintCallable)
    void ForceNextAttack(UEnemyAIAttackData* InAttackPtr);
    
    UFUNCTION(BlueprintCallable)
    void ForceExecuteDelayedAttack(UEnemyAIAttackData* InAttackPtr, float InDelay);
    
    UFUNCTION(BlueprintCallable)
    void ForceExecuteAttack(UEnemyAIAttackData* InAttackPtr);
    
    UFUNCTION(BlueprintCallable)
    void ForceDisengagedState();
    
    UFUNCTION(BlueprintCallable)
    void ForceChooseAttack(UEnemyAIAttackData* InAttackPtr);
    
    UFUNCTION(BlueprintCallable)
    void ForceAttackState();
    
    UFUNCTION(BlueprintCallable)
    void ForceAttack(UEnemyAIAttackData* InAttackPtr, bool bBypassPerception);
    
    UFUNCTION(BlueprintCallable)
    void FireWeaponAOE1(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindAvailableStoredWeaponSocket(AEnemyAIWeapon* InWeaponPtr, FName& OutSocketName) const;
    
    UFUNCTION(BlueprintCallable)
    void EnemyRemoveFromManager(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void EnemyAddToManager(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void EndAttack();
    
    UFUNCTION(BlueprintCallable)
    void EnableWeaponCollision();
    
    UFUNCTION(BlueprintCallable)
    void EnableTrackMeleePoints(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void EnableShieldCollision();
    
    UFUNCTION(BlueprintCallable)
    void EnableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void EnableImmediateAttack(bool ShouldEnable);
    
    UFUNCTION(BlueprintCallable)
    AActor* DisarmWeapon(float ScaleForce);
    
    UFUNCTION(BlueprintCallable)
    AActor* DisarmShield(float ScaleForce);
    
    UFUNCTION(BlueprintCallable)
    void DisableWeaponCollision();
    
    UFUNCTION(BlueprintCallable)
    void DisableShieldCollision();
    
    UFUNCTION(BlueprintCallable)
    void DisableProvidedWeaponCollision(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void DestroySpawnedChildren();
    
    UFUNCTION(BlueprintCallable)
    void DestroyAnimagusForm();
    
    UFUNCTION(BlueprintCallable)
    void ComboEnd(int32 ComboCount);
    
    UFUNCTION(BlueprintCallable)
    bool ChooseCounterAttackSplit(const FGameplayTagContainer& InTagContainer);
    
    UFUNCTION(BlueprintCallable)
    bool ChooseAttackUpdate();
    
    UFUNCTION(BlueprintCallable)
    UEnemyAIAttackData* ChooseAttack();
    
    UFUNCTION(BlueprintCallable)
    void CastSpellAtRandom(USpellToolRecord* SpellToolRecord, FName InSocketName);
    
    UFUNCTION(BlueprintCallable)
    void CastSpellAtLocation(const FVector& TargetLocation, USpellToolRecord* SpellToolRecord, const FName& InSocketName);
    
    UFUNCTION(BlueprintCallable)
    void CastSpellAtActor(AActor* InTargetPtr, USpellToolRecord* SpellToolRecord, FName InSocketName, const bool bAlwaysHitTargetActor);
    
    UFUNCTION(BlueprintCallable)
    void CastSpell(USpellToolRecord* SpellToolRecord, FName InSocketName);
    
    UFUNCTION(BlueprintCallable)
    void CastProtegoSpell(USpellToolRecord* SpellToolRecord, FName InSocketName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanStoreWeapon(AEnemyAIWeapon* InWeaponPtr) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAnyStoredWeaponBeThrown() const;
    
    UFUNCTION(BlueprintCallable)
    void BroadcastOnDeath(AActor* pActor);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastOnAlertSenseChanged(float alertSense);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastAlertState();
    
    UFUNCTION(BlueprintCallable)
    void BroadcastAlertSense();
    
    UFUNCTION(BlueprintCallable)
    bool AttackUpdateStateUpdate(EEnemy_AttackUpdateState AttackUpdateState, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void AttackTreeUpdate();
    
    UFUNCTION(BlueprintCallable)
    void AttackExecuteBTInject();
    
    UFUNCTION(BlueprintCallable)
    void AttackedEvent(AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    void AttackChooseBTInject();
    
    UFUNCTION(BlueprintCallable)
    void ApplyDesynchronization();
    
    UFUNCTION(BlueprintCallable)
    void ApparateDoneEvent(AActor* InApparateActor);
    
    UFUNCTION(BlueprintCallable)
    void ApparateArrivedEvent(AActor* InApparateActor, FVector InLoc);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void AllWeaponsLifetimeToZero() const;
    
    UFUNCTION(BlueprintCallable)
    void AllowSingleAttack();
    
    UFUNCTION(BlueprintCallable)
    void AllowHideBlindWeapon(bool bInAllow);
    
    UFUNCTION(BlueprintCallable)
    bool AdvancePath();
    
    UFUNCTION(BlueprintCallable)
    void AdjustAttackWeightsByID(const FString& InRegistryID);
    
    UFUNCTION(BlueprintCallable)
    void AddQBUpdateData(EEnemy_AttackLocSource InSource);
    
    UFUNCTION(BlueprintCallable)
    void ActivateRequiredWeapon();
    
    UFUNCTION(BlueprintCallable)
    void AcquireWeapon(AEnemyAIWeapon* InWeaponPtr);
    
    UFUNCTION(BlueprintCallable)
    void AcquireSpellCaster(ASpellCasterTool* InSpellCasterPtr);
    
    UFUNCTION(BlueprintCallable)
    void AcquireShield(AEnemyAIWeapon* InShieldPtr);
    
    UFUNCTION(BlueprintCallable)
    void AbortAUS(bool bBranchToIdle);
    
    UFUNCTION(BlueprintCallable)
    void AbortAttack();
    
};

