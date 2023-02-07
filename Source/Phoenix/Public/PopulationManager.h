#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "DatabaseName.h"
#include "ECollisionResponsePriority.h"
#include "ESEPrecacheFleshPriority.h"
#include "ETier4Type.h"
#include "HouseIds.h"
#include "PhxDbRegistryTypeManager.h"
#include "PopulationT4ActorRequestCompletedDelegate.h"
#include "StationQueryData.h"
#include "PopulationManager.generated.h"

class AActor;
class ATier4_Actor;
class ULevel;
class UObject;
class UPopulationConfigData;
class UPopulationManager;
class UScheduledEntity;
class UStationComponent;
class UWorld;

UCLASS(Blueprintable)
class PHOENIX_API UPopulationManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* PreloadedSocialReasoningClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPopulationConfigData* ApparateAbilityMapping;
    
public:
    UPopulationManager();
    UFUNCTION(BlueprintCallable)
    bool UpdateLocationSchedule(FName inScheduleKey, FName inActivityTypeID, bool inActivate, bool inHideImmediatelyOnDeactivate);
    
    UFUNCTION(BlueprintCallable)
    void TriggerUpdate(UScheduledEntity* InScheduledEntity);
    
    UFUNCTION(BlueprintCallable)
    bool StartSettingCollisionResponseOnSE(AActor* InActor, const TEnumAsByte<ECollisionResponse> InCollisionResponse, const ECollisionResponsePriority InPriority, const UObject* InProvider, FName InProviderName);
    
    UFUNCTION()
    AActor* Spawn(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod inCollisioinMethod, ULevel* InOverrideLevel, UObject* InParentContainer);
    
    UFUNCTION(BlueprintCallable)
    static bool ServiceStationWithNPC(const FString& InEntityName, const UStationComponent* InStationComponent);
    
    UFUNCTION(BlueprintCallable)
    void RequestT4Actor(const TEnumAsByte<ETier4Type> InT4Type, UPARAM(Ref) FTransform& InSpawnTransform, FPopulationT4ActorRequestCompleted OnCompleted, const TEnumAsByte<HouseIds> InHouse, const bool InAllowFemale, const bool InAllowMale);
    
    UFUNCTION(BlueprintCallable)
    UScheduledEntity* RequestCustomHobo(const FString& HoboName, const FVector& InLocation, const bool InIsMale);
    
    UFUNCTION(BlueprintCallable)
    void RequestCachedCharacter(FName InCharacterID, FName InWorldID);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCachedCharacter(FName InCharacterID, FName InWorldID);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseT4Actor(ATier4_Actor* InT4Actor);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseHoboAndEndPrecaching(UScheduledEntity* InScheduledEntity, bool InDestroyImmediate, bool bInIgnoreVisibilityChecks, bool bInIgnoreWanderOnRelease, ESEPrecacheFleshPriority InPriority, UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseHobo(UScheduledEntity* InScheduledEntity, bool InDestroyImmediate, bool InIgnoreVisibilityChecks, bool bInIgnoreWanderOnRelease);
    
    UFUNCTION(BlueprintCallable)
    static bool PlaceScheduledEntityBP(const FString& EntityName, const FTransform& InTransform);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_WaitForPlayerActor(const AActor* InActor, const float InLocation);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_WaitForPlayer(const FString& InName, const float InDistance);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_TeleportToLocation(const FString& InName);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_MoveToLocationActor(const AActor* InActor, const FVector& InLocation, const float InForcedSpeed);
    
    UFUNCTION(BlueprintCallable)
    bool PerformTask_MoveToLocation(const FString& InName, const FVector& InLocation, const float InForcedSpeed);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStartOfFirstDay();
    
    UFUNCTION(BlueprintCallable)
    void OnFleshDestroyed(AActor* InActor, UScheduledEntity* InScheduledEntity);
    
    UFUNCTION(BlueprintCallable)
    void OnFleshCreated(AActor* InActor, UScheduledEntity* InScheduledEntity);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool JoinStation(UObject* InJoiningObject, const FStationQueryData& StationData, float InDuration, bool OverwritePreviousGoal);
    
    UFUNCTION(BlueprintCallable)
    static bool IsScheduledEntityBP(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    bool IsAttendingActivityName(const FString& InName, const FString& InActivityName);
    
    UFUNCTION(BlueprintCallable)
    bool IsAttendingActivityActor(const FString& InActivityName, AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    UScheduledEntity* GetScheduledEntityFromName(const FString& EntityName);
    
    UFUNCTION(BlueprintCallable)
    UScheduledEntity* GetScheduledEntityFromActor(const AActor* InActor, const bool bAssertIfNotFound);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetCharacterFromDatabase(const FDatabaseName DatabaseName);
    
    UFUNCTION(BlueprintCallable)
    static AActor* GetActorFromEntityNameBP(const FString& EntityName, bool bInCanLookInCache);
    
    UFUNCTION(BlueprintCallable)
    static UPopulationManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingCollisionResponseOnSE(AActor* InActor, const ECollisionResponsePriority InPriority, const UObject* InProvider, FName InProviderName);
    
    UFUNCTION(BlueprintCallable)
    void EnableSeatFillers(bool inActivate);
    
    UFUNCTION(BlueprintCallable)
    static bool EnableScheduling(const FString& InEntityName, const bool InEnable);
    
    UFUNCTION(BlueprintCallable)
    static bool EnableDistanceBasedLOD(const FString& InEntityName, const bool InEnable);
    
    UFUNCTION(BlueprintCallable)
    bool CreateScheduleAtLocationWithKey(const FVector& InLocation, const FString& InKey);
    
    UFUNCTION(BlueprintCallable)
    bool CreateItemAsScheduledEntity(const FString& InItemID);
    
    UFUNCTION(BlueprintCallable)
    bool BroadCastScheduleKey(const FString& InKey, const bool InTemporary);
    
};

