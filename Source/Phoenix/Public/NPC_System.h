#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "AddToManagerEventDelegate.h"
#include "AssetTrackerData.h"
#include "BossFightData.h"
#include "BossFightEventDelegate.h"
#include "BossFightStartedDelegate.h"
#include "BossFightStopedDelegate.h"
#include "CombatBeginsEventDelegate.h"
#include "CombatEndsEventDelegate.h"
#include "DifficultyScaleData.h"
#include "EBossStates.h"
#include "EGameEvent_Intensity.h"
#include "ENPC_CombatThreatLevel.h"
#include "ENPC_ManagerType.h"
#include "Enemy_ParryWindowSetupData.h"
#include "HighestEnemyChangedEventDelegate.h"
#include "PostDeath_Params.h"
#include "RemoveFromManagerEventDelegate.h"
#include "NPC_System.generated.h"

class AActor;
class ADynamicObjectVolume;
class AMunitionType_Base;
class ANPC_Character;
class UEnemyWeapon_Manager;
class UNPC_Manager;
class UNPC_System;

UCLASS(Blueprintable)
class UNPC_System : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCombatBeginsEvent CombatBeginsEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCombatEndsEvent CombatEndsEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossFightEvent BossFightChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossFightStarted BossFightStartEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBossFightStoped BossFightEndEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FDifficultyScaleData> DifficultyScaleDataMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FBossFightData> BossFightTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FAssetTrackerData> SpawnTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, UNPC_Manager*> NPCManagerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyWeapon_Manager* WeaponManager;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHighestEnemyChangedEvent HighestEnemyChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRemoveFromManagerEvent RemoveFromManagerEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAddToManagerEvent AddToManagerEvent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> NonNPCList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ANPC_Character*> PostDeath_PendingNPCs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ANPC_Character*, FTimerHandle> PostDeath_ManagedNPCs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostDeath_Params PostDeath_Params;
    
    UNPC_System();
    UFUNCTION(BlueprintCallable)
    void TrackObject(const FString& ObjectName, AActor* ParentObject, AActor* ChildObject);
    
    UFUNCTION(BlueprintCallable)
    void TrackerCallback(AActor* ChildObject);
    
    UFUNCTION(BlueprintCallable)
    void TerminateAllBossFights();
    
    UFUNCTION(BlueprintCallable)
    void StartWandLinkEvent(AActor* TargetActor, TArray<AActor*> ExcludeListAlways, TArray<AActor*> ExcludeListOnce);
    
    UFUNCTION(BlueprintCallable)
    void StartBossFight(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    void SetToDead(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void SetOverrideThreatLevel(ENPC_CombatThreatLevel InThreatLevel);
    
    UFUNCTION(BlueprintCallable)
    void SetLoadoutConfigurationContext(const FString& InContext);
    
    UFUNCTION(BlueprintCallable)
    static void SetCanPerceivePlayerStatic(bool bCanPerceive);
    
    UFUNCTION(BlueprintCallable)
    void SetBossFightState(FName InBossFightName, EBossStates InBossState);
    
    UFUNCTION(BlueprintCallable)
    void SetBossFightCharacter(FName InBossFightName, AActor* InBossCharacterPtr);
    
    UFUNCTION(BlueprintCallable)
    static void SendHermesMessageToDOVActors(ADynamicObjectVolume* InDOVPtr, FName InMessage);
    
    UFUNCTION(BlueprintCallable)
    void SelectCycle();
    
    UFUNCTION(BlueprintCallable)
    static void ReportGameEvent(FGameplayTagContainer TagContainer, FVector Location, EGameEvent_Intensity Intensity, float Duration, float Range, float Falloff, AActor* Instigator, bool bTrackBackToInstigator, AActor* Target, FName Name);
    
    UFUNCTION(BlueprintCallable)
    void RemoveObject(AActor* ChildObject);
    
    UFUNCTION(BlueprintCallable)
    void RemoveNonNPC(AActor* NonNPCPtr);
    
    UFUNCTION(BlueprintCallable)
    void RemoveFromManager(AActor* InActorPtr);
    
private:
    UFUNCTION(BlueprintCallable)
    void PostDeath_TimerModeCallback();
    
    UFUNCTION(BlueprintCallable)
    void PostDeath_CleanupCallback(ANPC_Character* InNPCCharacter);
    
public:
    UFUNCTION(BlueprintCallable)
    static int32 ParryLaunchedProjectileStart(const FEnemy_ParryWindowSetupData& InSetupData, AActor* InOwner, AActor* InProjectile, float InVelocityMag, float InPostParryVelocityMag);
    
    UFUNCTION(BlueprintCallable)
    static void ParryLaunchedProjectileNotifyMunitionCreated(int32 InWindowID, AActor* InOwnerPtr, AActor* InTargetPtr, AMunitionType_Base* InMunitionPtr);
    
    UFUNCTION(BlueprintCallable)
    static void ParryLaunchedProjectileEnd(int32 InWindowID);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainRaised();
    
    UFUNCTION(BlueprintCallable)
    void OnCurtainLowered();
    
    UFUNCTION(BlueprintCallable)
    void OnBossDeadEvent(AActor* DeadActor);
    
    UFUNCTION(BlueprintCallable)
    static void KillNPC(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void KilledEvent(AActor* EnemyPtr, AActor* KilledByPtr, bool bKilledByPlayer, bool bPlayCameraCut);
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayerInCombat();
    
    UFUNCTION(BlueprintCallable)
    bool IsBossFightActive();
    
    UFUNCTION(BlueprintCallable)
    void GetTrackedChildren(AActor* ParentObject, TArray<AActor*>& FoundChildren);
    
    UFUNCTION(BlueprintCallable)
    FAssetTrackerData GetObjectTracker(const FString& ObjectName);
    
    UFUNCTION(BlueprintCallable)
    void GetNPCsByTypeWithinRadius(const ENPC_ManagerType ManagerType, const FVector& SourceLocation, const float Radius, TArray<AActor*>& FoundNPCs);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetClosest(AActor* NPCPtr) const;
    
    UFUNCTION(BlueprintCallable)
    EBossStates GetBossFightState(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    FName GetBossFightNameFromBossCharacter(AActor* BossActor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetBossFightName(FName BossDbId);
    
    UFUNCTION(BlueprintCallable)
    FBossFightData GetBossFightData(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetBossFightCharacter(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    static UNPC_System* Get();
    
    UFUNCTION(BlueprintCallable)
    void FollowAttackTimeout();
    
    UFUNCTION(BlueprintCallable)
    void FinishAvadaKedavraEvent();
    
    UFUNCTION(BlueprintCallable)
    void EndWandLinkEvent();
    
    UFUNCTION(BlueprintCallable)
    void EndBossFight(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    void EnableTargetPerception(AActor* InActorPtr, bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void EnableCombat(AActor* InActorPtr, bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void ClearLoadoutConfigurationContext();
    
    UFUNCTION(BlueprintCallable)
    void ChangeManager(AActor* InActorPtr, FGameplayTag InNewTag);
    
    UFUNCTION(BlueprintCallable)
    static bool CanPerceivePlayerStatic();
    
    UFUNCTION(BlueprintCallable)
    static bool AnyNPCLOSPlayer();
    
    UFUNCTION(BlueprintCallable)
    static bool AnyNPCAwareOfPlayer();
    
    UFUNCTION(BlueprintCallable)
    static bool AnyNPCAttackingPlayer();
    
    UFUNCTION(BlueprintCallable)
    void AdvanceBossFightSystem(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceBossFightManual(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceBossFight(FName InBossFightName);
    
    UFUNCTION(BlueprintCallable)
    void AddToManager(AActor* InActorPtr);
    
    UFUNCTION(BlueprintCallable)
    void AddNonNPC(AActor* NonNPCPtr);
    
};

