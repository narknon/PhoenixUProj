#include "LocationBasedDatabaseTables.h"

class AAmbientCreatureSpawnVolume;
class ADynamicObjectVolume;
class AFastTravelLocation;
class AMountZoneVolumeBase;
class UWorldEventCondition;

void ULocationBasedDatabaseTables::RecordWorldEventLocationMeta(const FString& Name, const float StreamInRadius, const float StreamOutRadius) {
}

void ULocationBasedDatabaseTables::RecordWorldEventDatabaseLocation(const FString& Name, const FString& Guid, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordWorldEventDatabaseDescriptors(const FString& Name, const FGameplayTagContainer& locationDescriptors, const TArray<TSoftObjectPtr<UWorldEventCondition>> Conditions) {
}

void ULocationBasedDatabaseTables::RecordVaultDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordTentDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordSphinxPuzzleDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordRuinDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordObjectAndOwner(const FString& Name, const FString& Owner) {
}

void ULocationBasedDatabaseTables::RecordMountZoneLocation(const AMountZoneVolumeBase* InVolume) {
}

void ULocationBasedDatabaseTables::RecordMiscDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordKnowledgeLocationDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordKnowledgeInvestigatableDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordHamletDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordFastTravelDatabaseLocation(const FString& Name, FVector Position, FVector BeaconPosition, float ZRot, AFastTravelLocation* locationActor) {
}

void ULocationBasedDatabaseTables::RecordEnemyDenLocationsDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordDungeonChestDatabaseOwner(const FString& Name, const FString& Owner) {
}

void ULocationBasedDatabaseTables::RecordDungeonChestDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordDevMiscDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordDevBanditCampDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordClusterDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordChestDatabaseOwner(const FString& Name, const FString& Owner) {
}

void ULocationBasedDatabaseTables::RecordCharacterSpawnLocation(const ADynamicObjectVolume* InVolume) {
}

void ULocationBasedDatabaseTables::RecordBroomTestPaths() {
}

void ULocationBasedDatabaseTables::RecordBroomRacePath(const FString& RaceName, const FString& PathName, const int32 PathIndex, const TArray<FVector>& PathPoints) {
}

void ULocationBasedDatabaseTables::RecordBroomRaceGates(const FString& RaceName, const TArray<FTransform>& RaceGateTransforms, const TArray<FString>& GateTypes) {
}

void ULocationBasedDatabaseTables::RecordBeastDenDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordBanditCampDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordAncientMagicDatabaseLocation(const FString& Name, FVector Position, float ZRot) {
}

void ULocationBasedDatabaseTables::RecordAmbientCreatureSpawnLocation(const AAmbientCreatureSpawnVolume* InVolume) {
}

void ULocationBasedDatabaseTables::GetWorldEventLocations(const FGameplayTagContainer& LocationRequiredDescriptors, const FGameplayTagContainer& LocationDeniedDescriptors, TArray<FEventLocationResult>& OutResults) {
}

ULocationBasedDatabaseTables::ULocationBasedDatabaseTables() {
}

