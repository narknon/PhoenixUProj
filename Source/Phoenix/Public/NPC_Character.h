#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Camera/PlayerCameraManager.h"
#include "GameplayTagContainer.h"
#include "MunitionToInstigatorData.h"
#include "OdcPathSpec.h"
#include "EStandardManagedPriority.h"
#include "VariantMapHandle.h"
#include "Ability_Character_Interface.h"
#include "Base_Character.h"
#include "EActor_LoadDBProcessingType.h"
#include "ECreatureMovementSpeed.h"
#include "ECreatureStance.h"
#include "EEnemy_CharacterState.h"
#include "ENPC_PathSpec.h"
#include "ENPC_PerceptionUpdate.h"
#include "ENPC_QBUpdate.h"
#include "ENPC_Type.h"
#include "Enemy_CharacterParams.h"
#include "NPCAbilityFinishedDelegate.h"
#include "NPCAvadaKedavraDelegateDelegate.h"
#include "NPCCustomAbilityFinishedDelegate.h"
#include "NPCDiedDelegateDelegate.h"
#include "NPCLostPerceivePlayerDelegate.h"
#include "NPCLostPerceptionPlayerDelegate.h"
#include "NPCPerceivePlayerDelegate.h"
#include "NPCPerceivedByPlayerDelegate.h"
#include "NPCTransformedDelegateDelegate.h"
#include "NPCWasPerceivedByPlayerDelegate.h"
#include "NPC_Character_Interface.h"
#include "NPC_LOSTraceParams.h"
#include "NPC_PathSpec.h"
#include "NPC_ShowUI.h"
#include "NPC_TargetPerceptionParams.h"
#include "TargetPerceptionDoneEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "NPC_Character.generated.h"

class AActor;
class ANPC_Character;
class ANPC_Controller;
class APerceptionPointArea;
class APerformTasksForAI;
class UAISense;
class UAblAbility;
class UActorComponent;
class UBehaviorTree;
class UBlackboardComponent;
class UBlackboardData;
class UCapsuleComponent;
class UCognitionComponent;
class UCognitionStimuliSourceComponent;
class UCombativePlantComponent;
class UCreature_MotionTable;
class UCustomizableCharacterComponent;
class UDataTable;
class UEnemy_TargetSenseAsset;
class UInteractionArchitectAsset;
class UNPC_BTComponent;
class UNPC_Component;
class UNPC_PerceptionUpdateDataAsset;
class UNPC_QBUpdateDataAsset;
class UNPC_ReactionComponent;
class UObject;
class UPerceptionIconData;
class USocialAgentPathFollowerComponent;

UCLASS(Blueprintable)
class PHOENIX_API ANPC_Character : public ABase_Character, public INPC_Character_Interface, public IAbility_Character_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Type NPCType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GroupTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviorTreePtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* BehaviorTreeDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBlackboardComponent* BlackboardComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBlackboardData* EmptyBlackboardAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNPC_BTComponent* BTComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionComponent* CognitionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USocialAgentPathFollowerComponent* SocialAgentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNPC_Component* NPCComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CCComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CogSourceComp;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNPC_ReactionComponent* NPCReactionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCombativePlantComponent* CombativePlantComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QBUpdatesSupported;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PerceptionUpdatesSupported;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNPC_QBUpdateDataAsset* QBUpdateDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNPC_PerceptionUpdateDataAsset* PerceptionUpdateDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_CharacterParams Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemy_TargetSenseAsset* TargetSenseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableBeacon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BeaconIconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowDBInstanceRedirect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCreateScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowVulnerabilityIndicators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OverrideScheduleTableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DefaultScheduleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DefaultWorldID;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 PatrolPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddSocialScoreToPatrol;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseNPCController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCommitsACrimeWhenKilling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBePickpocketed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_ShowUI ShowUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageDisplayHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamageDisplayExtraOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_PathSpec DefaultPathSpec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNPC_PathSpec> PathSpecList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_LOSTraceParams TargetLOSParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_LOSTraceParams CrimeSceneLOSParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_LOSTraceParams AttackLOSParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_LOSTraceParams WaypointLOSParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_LOSTraceParams DebugLOSParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LOSRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathEffectDelayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDissolveOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InstantDissolveChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DissolveDelayMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DissolveDelayMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DissolveDestroyDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFadeOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoNewDeathFade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoDeathCamOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FViewTargetTransitionParams TransitionParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathCamDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeathCamDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoBulletTimeOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletTimeDilation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletTimeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BulletTimeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHaltDeathCamOnBulletTimeStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StealAmmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InventoryKnuts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FromNPCDamageMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FromPlayerDamageMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToPlayerDamageMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowReleaseOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_TargetPerceptionParams TargetPerceptionParams;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetPerceptionDoneEvent TargetPerceptionDoneEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideCharacterLook;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideCharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideVoice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideVoiceID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCPerceivePlayer PerceivePlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCPerceivePlayer CombatPerceivePlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCLostPerceivePlayer LostPerceivePlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCLostPerceptionPlayer LostPerceptionPlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCLostPerceivePlayer CombatLostPerceivePlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCLostPerceptionPlayer CombatLostPerceptionPlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCPerceivedByPlayer PerceivedByPlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCWasPerceivedByPlayer WasPerceivedByPlayerDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCCustomAbilityFinished CustomAbilityFinishedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCAbilityFinished AbilityFinishedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCDiedDelegate NPCDiedDelegate;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCTransformedDelegate NPCTransformedDelegate;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPCAvadaKedavraDelegate NPCAvadaKedavraDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ANPC_Controller* NPCControllerPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerceptionIconData* MinimapPerceptionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* DefaultMunition;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVariantMapHandle NPCVariantMapHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureStance DesiredCreatureStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureStance CurrentCreatureStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureStance NextCreatureStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureMovementSpeed CurrentCreatureGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureMovementSpeed NextCreatureGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInCreatureIdleVariation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreature_MotionTable* MotionTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveToStopDistanceTune;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableCreatureTurnNavChecks;
    
    ANPC_Character();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WillAttackPlayer() const;
    
    UFUNCTION(BlueprintCallable)
    void Unfreeze();
    
    UFUNCTION(BlueprintCallable)
    void TargetSighted(UAISense* Sense, const AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void TargetLost(UAISense* Sense, const AActor* OldTarget);
    
    UFUNCTION(BlueprintCallable)
    void TargetChanged(UAISense* Sense, const AActor* NewTarget, const AActor* OldTarget);
    
    UFUNCTION(BlueprintCallable)
    void StopDeathCam();
    
    UFUNCTION(BlueprintCallable)
    void StopBulletTime();
    
    UFUNCTION(BlueprintCallable)
    static void StartSuspendEnemies(bool bSuspended, EStandardManagedPriority Priority, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingSuspendAiState(bool bSuspended, EStandardManagedPriority Priority, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void StartFadeOut();
    
    UFUNCTION(BlueprintCallable)
    void StartFadeIn();
    
    UFUNCTION(BlueprintCallable)
    void StartDissolve();
    
    UFUNCTION(BlueprintCallable)
    void StartDeathCam();
    
    UFUNCTION(BlueprintCallable)
    void StartCustomAbility(TSubclassOf<UAblAbility> InAbility, bool bUseCustomPause, bool bClearPauseWhenFinished, bool bPreventReactions, bool bShouldReenableReactions);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartChildSpawnFX(FTransform inSpawnLoc);
    
    UFUNCTION(BlueprintCallable)
    void StartBulletTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowHealthBar() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldShowBadge() const;
    
    UFUNCTION(BlueprintCallable)
    void SetupBehaviorTreeForced();
    
    UFUNCTION(BlueprintCallable)
    void SetUnawareState(EEnemy_CharacterState InState);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetAimSense();
    
    UFUNCTION(BlueprintCallable)
    void SetStayInVolumeParams(float inStayInRadius, float inStayInVolumeTeleportTimeout, bool inStayInVolumeOffNavTeleport);
    
    UFUNCTION(BlueprintCallable)
    void SetShowPerceptionIndicator(bool bInShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowName(bool bInShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowHealthBar(bool bInShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowDamage(bool bInShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowCallout(bool bInShow);
    
    UFUNCTION(BlueprintCallable)
    void SetShowBadge(bool bInShow);
    
    UFUNCTION(BlueprintCallable)
    void SetNewDefaultPerformTask(APerformTasksForAI* NewDefaultTrigger, bool bForceStart, bool bLoopWhenFinished);
    
    UFUNCTION(BlueprintCallable)
    void SetForcedPlayerPerception(bool InCanPerceive, bool bKeepAlwaysOn);
    
    UFUNCTION(BlueprintCallable)
    void SetDamageToPlayerMult(float InScale);
    
    UFUNCTION(BlueprintCallable)
    void SetDamageFromPlayerMult(float InScale);
    
    UFUNCTION(BlueprintCallable)
    void SetDamageFromNPCMult(float InScale);
    
    UFUNCTION(BlueprintCallable)
    void SetCanPerceivePlayer(bool bShouldExclude);
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysPerceiveAsTarget(bool InFlag);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowTargetAimSense(bool InAllow);
    
    UFUNCTION(BlueprintCallable)
    void RestoreStayInVolumeParamDefaults();
    
    UFUNCTION(BlueprintCallable)
    void RemoveStayInVolume(APerceptionPointArea* InArea);
    
    UFUNCTION(BlueprintCallable)
    void RemoveQBUpdateSupported(ENPC_QBUpdate InQBUpdate);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllStayInVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ReleaseIntroductionCharacter(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void Release(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void RagdollImpact();
    
    UFUNCTION(BlueprintCallable)
    void ProtectIntroductionCharacter(AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStationOnFinishedExit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStationOnFinishedEnter();
    
    UFUNCTION(BlueprintCallable)
    void OnPTTaskComplete(int32 InTaskIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnPTComplete(const APerformTasksForAI* InPTPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnChildSpawnFX(FTransform inSpawnLoc);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterDBLoadCompleted(AActor* LoadActor, TEnumAsByte<EActor_LoadDBProcessingType> LoadType);
    
    UFUNCTION(BlueprintCallable)
    static bool NPCWillAttackPlayer(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    static FNPC_TargetPerceptionParams NPCGetTargetPerceptionParams(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    static ANPC_Character* NPCEnableTimedAttackPerception(AActor* InActorPtr, FName InTeamName, float InTime, AActor* InTarget);
    
    UFUNCTION(BlueprintCallable)
    static ANPC_Character* NPCEnableNotifyPerception(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    static ANPC_Character* NPCEnableCrimeScenePerception(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    static ANPC_Character* NPCEnableAttackPerception(AActor* InActorPtr, FName InTeamName);
    
    UFUNCTION(BlueprintCallable)
    static void NPCDisableNotifyPerception(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    static void NPCDisableCrimeScenePerception(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    static void NPCDisableAttackPerception(AActor* InActorPtr);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NewDeathFade();
    
public:
    UFUNCTION(BlueprintCallable)
    void MunitionToInstigator(const UObject* i_caller, const FMunitionToInstigatorData& InMunInstData);
    
    UFUNCTION(BlueprintCallable)
    void Kill();
    
    UFUNCTION(BlueprintCallable)
    bool IsScheduledEntity();
    
    UFUNCTION(BlueprintCallable)
    static bool IsRootComponent(UActorComponent* InComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReleased() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsQBUpdateSupported(ENPC_QBUpdate InQBUpdate) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPerceptionUpdateSupported(ENPC_PerceptionUpdate InPerceptionUpdate) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCreatureAnimationTransition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCreatureAnimationStanceTransition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCreatureAnimationGaitTransition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFrozen() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAiSuspended() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasTaskTag(FGameplayTag InTaskTag);
    
    UFUNCTION(BlueprintCallable)
    void HandleRagdollImpact(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FNPC_TargetPerceptionParams GetTargetPerceptionParams() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowUIPerceptinCone() const;
    
    UFUNCTION(BlueprintCallable)
    FNPC_ShowUI GetShowUI();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowPerceptionIndicator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowHealthBar() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowCallout() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowBadge() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENPC_Type GetNPCType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FOdcPathSpec GetNPCPathSpec(ENPC_PathSpec InPathSpec) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UCapsuleComponent* GetNpcCapsuleComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetImpactLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetImpactDirection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEnemy_CharacterParams GetCharacterParams() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAlwaysPerceiveAsTarget() const;
    
    UFUNCTION(BlueprintCallable)
    void Freeze();
    
    UFUNCTION(BlueprintCallable)
    void ForceScheduledEntityState();
    
    UFUNCTION(BlueprintCallable)
    void ForceProtego(bool inProtegoOnOff);
    
    UFUNCTION(BlueprintCallable)
    static void FinishSuspendEnemies(EStandardManagedPriority Priority, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingSuspendAiState(EStandardManagedPriority Priority, const UObject* Provider);
    
    UFUNCTION(BlueprintCallable)
    void EndCustomAbility();
    
    UFUNCTION(BlueprintCallable)
    void EnablePerception(const UObject* i_caller);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EnableMinimapPerceptionCone(ANPC_Character* NPCCharacter);
    
public:
    UFUNCTION(BlueprintCallable)
    void EnableCallout(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void EnableBeacon(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void DisablePerception(const UObject* i_caller);
    
protected:
    UFUNCTION(BlueprintCallable)
    void DisableMinimapPerceptionCone(ANPC_Character* NPCCharacter);
    
public:
    UFUNCTION(BlueprintCallable)
    void DisableCallout(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void DisableBeacon(const UObject* i_caller);
    
    UFUNCTION(BlueprintCallable)
    void DestroyOnDeath();
    
    UFUNCTION(BlueprintCallable)
    void DeathFxComplete();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DeathExplode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DeathDissolve();
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearForceScheduledEntityState();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CharacterDiedEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBePickpocketed() const;
    
    UFUNCTION(BlueprintCallable)
    void BroadcastNPC_AnimEvent(FName InName);
    
    UFUNCTION(BlueprintCallable)
    void AssignNPCLevelWRTPlayerLevel(const int32 ExpLevel, bool bIndicateHUD);
    
    UFUNCTION(BlueprintCallable)
    void ApplyTargetSenseAsset(UEnemy_TargetSenseAsset* InTargetSenseAsset);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplySpawnFX();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyReplicaFX();
    
    UFUNCTION(BlueprintCallable)
    void ApplyNPCPathSpecDirect(FOdcPathSpec InPathSpec);
    
    UFUNCTION(BlueprintCallable)
    void ApplyNPCPathSpec(ENPC_PathSpec InPathSpec);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyCharacterFX();
    
    UFUNCTION(BlueprintCallable)
    void AddStayInVolume(APerceptionPointArea* InArea);
    
    UFUNCTION(BlueprintCallable)
    void AddQBUpdateSupported(ENPC_QBUpdate InQBUpdate);
    
    UFUNCTION(BlueprintCallable)
    void AddPerceptionUpdateSupported(ENPC_PerceptionUpdate InPerceptionUpdate);
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void StopCustomAbility() override PURE_VIRTUAL(StopCustomAbility,);
    
    UFUNCTION(BlueprintCallable)
    void PlayCustomAbility(TSubclassOf<UAblAbility> InAbility, bool bPreventReactions) override PURE_VIRTUAL(PlayCustomAbility,);
    
};

