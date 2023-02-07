#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "CharacterShutdownProvider_Interface.h"
#include "ESEAllowBTShutdownPriority.h"
#include "ESEPrecacheFleshPriority.h"
#include "ESchedulingPriority.h"
#include "EStationExitCallBack.h"
#include "E_Goal.h"
#include "FleshLoadCompleteDelegate.h"
#include "GoalStatus.h"
#include "ScheduleEntry.h"
#include "ScheduledObject_Interface.h"
#include "StationInteractor_Interface.h"
#include "Templates/SubclassOf.h"
#include "ScheduledEntity.generated.h"

class AActor;
class AAntiSocialAAIController;
class ABase_Character;
class AFlyingBroom;
class APawn;
class ASocialNavigatorController;
class ASocialReasoning;
class ASocialSplineController;
class AStation;
class UAblAbility;
class UFlyingBroomPhysics;
class UPathComponent;
class UScheduledEntity;
class UStationComponent;

UCLASS(Blueprintable)
class PHOENIX_API UScheduledEntity : public UObject, public IScheduledObject_Interface, public IStationInteractor_Interface, public ICharacterShutdownProvider_Interface {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWaitForPlayerComplete);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStationInteractionExitComplete);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPerformTaskStationUseStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPerformTaskStationUseFinish);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPerformTaskStationFinishUseAfterGiventTime, const float, InFinishTime);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerformTaskComplete, UScheduledEntity*, ScheduledEntity, int32, ActivityTypeBits);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPerformCustomAction_NoLocation);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMoveToStationComplete);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMoveToLocationComplete);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractWithStationComplete);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFleshLoadComplete OnFleshLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformCustomAction_NoLocation OnPerformCustomAction_NoLocation;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTaskComplete OnPerformTaskComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMoveToLocationComplete OnMoveToLocationComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWaitForPlayerComplete OnWaitForPlayerComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMoveToStationComplete OnMoveToStationComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTaskStationUseStart OnPerformTaskStationUseStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTaskStationUseFinish OnPerformTaskStationUseFinish;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTaskStationFinishUseAfterGiventTime OnPerformTaskStationFinishUseAfterGivenTime;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractWithStationComplete OnInteractionWithStationComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStationInteractionExitComplete OnStationInteractionExitComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* FollowCamActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASocialNavigatorController* NavPathController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASocialSplineController* SplinePathController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAntiSocialAAIController* DefaultController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASocialReasoning* ScheduledEntitySocialReasoning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPathComponent* PathComponent_PT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStationComponent* StationComponent_MTS;
    
public:
    UScheduledEntity();
    UFUNCTION(BlueprintCallable)
    bool StartSchedulingOverride(const bool InValue, ESchedulingPriority InPriority, const UObject* InProvider, const bool bInProdcessValue, const bool bInForceExit, const bool bInProcessSchedule);
    
    UFUNCTION(BlueprintCallable)
    void StartPrecachingFlesh(ESEPrecacheFleshPriority InPriority, UObject* InCaller, float InPrecacheDistance, bool bInAutoFleshLock);
    
    UFUNCTION(BlueprintCallable)
    bool SetFlesh(ABase_Character* InFlesh);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentActorToAggro(const FName InRequiredTeam, const bool bEnableCombat);
    
    UFUNCTION(BlueprintCallable)
    void SetCompanionHighLOD(bool bHighLOD);
    
private:
    UFUNCTION(BlueprintCallable)
    void RequestHighLOD();
    
public:
    UFUNCTION(BlueprintCallable)
    void PerformTask_WaitForTime(const float InTime, const FString& InLocation);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_WaitForPlayerIsComplete();
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_WaitForPlayer(const float InDistance, bool InbOrientTowardsPlayer);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_TeleportToTransform(const FTransform& InTransform);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_TeleportToStation(const AStation* InStation, const bool bInInteract, const FString& InSocialAction, const int32 InConnectionIndex, const float InStationDurationOverride, bool InSkipValidation);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_TeleportToLocation(const FVector& InLocation);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_StopLumosOnNPC(bool bSuccess, bool bTimeout);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_StartLumosOnNPC(float Timeout, int32 InSpellLevel);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_StartCustomTask_NoLocation();
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_ReparoFinished(uint8 InAction);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_RemoveActivePerformTask();
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_PlaceAtTransform(const FTransform& InTransform);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_PlaceAtLocation(const FVector& InLocation);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_MoveToStation(const AStation* InStation, const FName InActionName, const bool bInInteract, const float InForceSpeed, const int32 InConnectionIndex, const float InStationDurationOverride);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_MoveToLocation(const FVector& InLocation, const float InForceSpeed, const bool InBTriggerNextActivity, const float InRadius, const UPathComponent* InPath);
    
    UFUNCTION(BlueprintCallable)
    AFlyingBroom* PerformTask_MountBroomWithFlightData(const TSubclassOf<AFlyingBroom> FlyingBroomClass, UFlyingBroomPhysics* StudentFlightData);
    
    UFUNCTION(BlueprintCallable)
    AFlyingBroom* PerformTask_MountBroom(const TSubclassOf<AFlyingBroom> FlyingBroomClass);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_FollowActor(AActor* InFollowActor, const float InForceSpeed);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_FinishCustomTask_NoLocation();
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_DismountBroom();
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_CustomSpellFinished(uint8 InAction);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_CastReparo(AActor* TargetPtr, float Timeout);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_CastCustomSpell(AActor* TargetPtr, float Timeout);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_ApparateOutActivity();
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_ApparateOut(const TSubclassOf<UAblAbility> InAblAbility);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_ApparateIn(const TSubclassOf<UAblAbility> InAblAbility);
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_ApparateFinishedActivity();
    
    UFUNCTION(BlueprintCallable)
    void PerformTask_ApparateFinished();
    
private:
    UFUNCTION(BlueprintCallable)
    void PawnOverlapBegin(AActor* InSelf, AActor* InOther);
    
public:
    UFUNCTION(BlueprintCallable)
    void Pause(bool bInPause);
    
    UFUNCTION(BlueprintCallable)
    bool IsWorldEventReleasedHobo();
    
    UFUNCTION(BlueprintCallable)
    bool IsWorldEventHobo();
    
    UFUNCTION(BlueprintCallable)
    bool IsWaitingForStation();
    
    UFUNCTION(BlueprintCallable)
    bool IsStudent();
    
    UFUNCTION(BlueprintCallable)
    bool IsSplineHobo();
    
    UFUNCTION(BlueprintCallable)
    bool IsSeatFillerHobo();
    
    UFUNCTION(BlueprintCallable)
    bool IsSceneRigHobo();
    
    UFUNCTION(BlueprintCallable)
    bool IsInTransit();
    
    UFUNCTION(BlueprintCallable)
    bool IsInPlayerInteraction();
    
    UFUNCTION(BlueprintCallable)
    bool IsHobo();
    
    UFUNCTION(BlueprintCallable)
    bool IsGhost();
    
    UFUNCTION(BlueprintCallable)
    bool IsGeneralHobo();
    
    UFUNCTION(BlueprintCallable)
    bool IsEnabled();
    
    UFUNCTION(BlueprintCallable)
    void GetUpcomingActivity(bool& ActivityIsValid, FScheduleEntry& UpcomingActivity);
    
    UFUNCTION(BlueprintCallable)
    ASocialReasoning* GetSocialReasoning();
    
    UFUNCTION(BlueprintCallable)
    void GetMinutesToUpcomingActivity(bool& ActivityIsValid, int32& MinutesToUpcomingActivity);
    
    UFUNCTION(BlueprintCallable)
    FVector GetLocation();
    
    UFUNCTION(BlueprintCallable)
    void GetGoalStatus(E_Goal::Type GoalType, FGoalStatus& GoalStatus);
    
    UFUNCTION(BlueprintCallable)
    void GetGoalActivity(E_Goal::Type GoalType, bool& ActivityIsValid, FScheduleEntry& RequestedActivity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawn* GetFlesh() const;
    
    UFUNCTION(BlueprintCallable)
    float GetExcessTravelTime(float InDeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ABase_Character* GetBaseCharacter() const;
    
    UFUNCTION(BlueprintCallable)
    bool FinishSchedulingOverride(ESchedulingPriority InPriority, const UObject* InProvider, const bool bInProcessValue, const bool bInForceExit, const bool bInProcessSchedule);
    
    UFUNCTION(BlueprintCallable)
    void EndPrecachingFlesh(ESEPrecacheFleshPriority InPriority, UObject* InCaller, bool bInAutoFleshLock);
    
    UFUNCTION(BlueprintCallable)
    void EnableSocialControl(const bool InEnable);
    
    UFUNCTION(BlueprintCallable)
    bool EnableScheduling(const bool InEnable, const bool bInForceExit, const bool bInProcessSchedule);
    
    UFUNCTION(BlueprintCallable)
    void DontAllowBTShutdown(ESEAllowBTShutdownPriority InPriority, UObject* InCaller);
    
private:
    UFUNCTION(BlueprintCallable)
    void DialogCompleteCallback();
    
public:
    UFUNCTION(BlueprintCallable)
    bool CurrentlyInFlesh();
    
private:
    UFUNCTION(BlueprintCallable)
    void CollisionResponseEnded(ASocialReasoning* SocialReasoning, FName SocialAction);
    
public:
    UFUNCTION(BlueprintCallable)
    void CanAllowBTShutdown(ESEAllowBTShutdownPriority InPriority, UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void AddThinkNowEvent(const FString& InText, float InDelayLow, float InDelayHigh, bool bInAllowBTShutdown);
    
    UFUNCTION(BlueprintCallable)
    bool AbandonStations(EStationExitCallBack InExitCallback);
    
    
    // Fix for true pure virtual functions not being implemented
};

