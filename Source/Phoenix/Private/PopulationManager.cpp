#include "PopulationManager.h"

class AActor;
class ATier4_Actor;
class ULevel;
class UObject;
class UPopulationManager;
class UScheduledEntity;
class UStationComponent;
class UWorld;

bool UPopulationManager::UpdateLocationSchedule(FName inScheduleKey, FName inActivityTypeID, bool inActivate, bool inHideImmediatelyOnDeactivate) {
    return false;
}

void UPopulationManager::TriggerUpdate(UScheduledEntity* InScheduledEntity) {
}

bool UPopulationManager::StartSettingCollisionResponseOnSE(AActor* InActor, const TEnumAsByte<ECollisionResponse> InCollisionResponse, const ECollisionResponsePriority InPriority, const UObject* InProvider, FName InProviderName) {
    return false;
}

AActor* UPopulationManager::Spawn(UWorld* InWorld, const FTransform& InTransform, const FString& InRegistryID, uint32 inParentUID, uint32 inOverrideUID, bool inIsPersistent, ESpawnActorCollisionHandlingMethod inCollisioinMethod, ULevel* InOverrideLevel, UObject* InParentContainer) {
    return NULL;
}

bool UPopulationManager::ServiceStationWithNPC(const FString& InEntityName, const UStationComponent* InStationComponent) {
    return false;
}

void UPopulationManager::RequestT4Actor(const TEnumAsByte<ETier4Type> InT4Type, FTransform& InSpawnTransform, FPopulationT4ActorRequestCompleted OnCompleted, const TEnumAsByte<HouseIds> InHouse, const bool InAllowFemale, const bool InAllowMale) {
}

UScheduledEntity* UPopulationManager::RequestCustomHobo(const FString& HoboName, const FVector& InLocation, const bool InIsMale) {
    return NULL;
}

void UPopulationManager::RequestCachedCharacter(FName InCharacterID, FName InWorldID) {
}

void UPopulationManager::RemoveCachedCharacter(FName InCharacterID, FName InWorldID) {
}

void UPopulationManager::ReleaseT4Actor(ATier4_Actor* InT4Actor) {
}

void UPopulationManager::ReleaseHoboAndEndPrecaching(UScheduledEntity* InScheduledEntity, bool InDestroyImmediate, bool bInIgnoreVisibilityChecks, bool bInIgnoreWanderOnRelease, ESEPrecacheFleshPriority InPriority, UObject* InCaller) {
}

void UPopulationManager::ReleaseHobo(UScheduledEntity* InScheduledEntity, bool InDestroyImmediate, bool InIgnoreVisibilityChecks, bool bInIgnoreWanderOnRelease) {
}

bool UPopulationManager::PlaceScheduledEntityBP(const FString& EntityName, const FTransform& InTransform) {
    return false;
}

bool UPopulationManager::PerformTask_WaitForPlayerActor(const AActor* InActor, const float InLocation) {
    return false;
}

bool UPopulationManager::PerformTask_WaitForPlayer(const FString& InName, const float InDistance) {
    return false;
}

bool UPopulationManager::PerformTask_TeleportToLocation(const FString& InName) {
    return false;
}

bool UPopulationManager::PerformTask_MoveToLocationActor(const AActor* InActor, const FVector& InLocation, const float InForcedSpeed) {
    return false;
}

bool UPopulationManager::PerformTask_MoveToLocation(const FString& InName, const FVector& InLocation, const float InForcedSpeed) {
    return false;
}

void UPopulationManager::OnStartOfFirstDay() {
}

void UPopulationManager::OnFleshDestroyed(AActor* InActor, UScheduledEntity* InScheduledEntity) {
}

void UPopulationManager::OnFleshCreated(AActor* InActor, UScheduledEntity* InScheduledEntity) {
}

bool UPopulationManager::JoinStation(UObject* InJoiningObject, const FStationQueryData& StationData, float InDuration, bool OverwritePreviousGoal) {
    return false;
}

bool UPopulationManager::IsScheduledEntityBP(AActor* InActor) {
    return false;
}

bool UPopulationManager::IsAttendingActivityName(const FString& InName, const FString& InActivityName) {
    return false;
}

bool UPopulationManager::IsAttendingActivityActor(const FString& InActivityName, AActor* InActor) {
    return false;
}

UScheduledEntity* UPopulationManager::GetScheduledEntityFromName(const FString& EntityName) {
    return NULL;
}

UScheduledEntity* UPopulationManager::GetScheduledEntityFromActor(const AActor* InActor, const bool bAssertIfNotFound) {
    return NULL;
}

FString UPopulationManager::GetCharacterFromDatabase(const FDatabaseName DatabaseName) {
    return TEXT("");
}

AActor* UPopulationManager::GetActorFromEntityNameBP(const FString& EntityName, bool bInCanLookInCache) {
    return NULL;
}

UPopulationManager* UPopulationManager::Get() {
    return NULL;
}

void UPopulationManager::FinishSettingCollisionResponseOnSE(AActor* InActor, const ECollisionResponsePriority InPriority, const UObject* InProvider, FName InProviderName) {
}

void UPopulationManager::EnableSeatFillers(bool inActivate) {
}

bool UPopulationManager::EnableScheduling(const FString& InEntityName, const bool InEnable) {
    return false;
}

bool UPopulationManager::EnableDistanceBasedLOD(const FString& InEntityName, const bool InEnable) {
    return false;
}

bool UPopulationManager::CreateScheduleAtLocationWithKey(const FVector& InLocation, const FString& InKey) {
    return false;
}

bool UPopulationManager::CreateItemAsScheduledEntity(const FString& InItemID) {
    return false;
}

bool UPopulationManager::BroadCastScheduleKey(const FString& InKey, const bool InTemporary) {
    return false;
}

UPopulationManager::UPopulationManager() {
    this->PreloadedSocialReasoningClass = NULL;
    this->ApparateAbilityMapping = NULL;
}

