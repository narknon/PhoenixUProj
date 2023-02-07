#include "BeaconManager.h"

class AActor;
class UBeaconInfo;
class UBeaconManager;
class UScheduledEntity;

void UBeaconManager::UpdateExpansionTentPlayer(FVector teleportPosition) {
}

void UBeaconManager::UnRegisterBeaconByHandleBP(int64 ObjectHandle) {
}

void UBeaconManager::SetBeaconStateByName(EBeaconType BeaconType, const FString& BeaconName, bool ActiveState) {
}

void UBeaconManager::SetBeaconStateBP(int32 ObjectHandle, EBeaconState BeaconState) {
}

void UBeaconManager::SetBeaconRangesByHandle(int32 ObjectHandle, int32 InActivationDist, int32 InEnterExitDist) {
}

int64 UBeaconManager::RegisterStaticBeaconBP(EBeaconType BeaconType, const FString& BeaconName, const FString& BeaconIcon, const FName& BeaconWorld, FVector BeaconPos, bool ShowOnHUD, bool ShowDistanceOnHud, FName BeaconableId) {
    return 0;
}

void UBeaconManager::RegisterSanctuaryExit(const FString& SanctuaryWorldName) {
}

void UBeaconManager::RegisterExpansionTent(const FString& tentID, FVector Position, bool bIsEntrance) {
}

int64 UBeaconManager::RegisterDynamicBeaconScheduledEntityBP(EBeaconType BeaconType, const FString& BeaconName, const FString& BeaconIcon, const FName& BeaconWorld, FVector BeaconPos, UScheduledEntity* NewBeaconScheduledEntity, bool ShowOnHUD, bool ShowDistanceOnHud) {
    return 0;
}

int64 UBeaconManager::RegisterDynamicBeaconObjectBP(EBeaconType BeaconType, const FString& BeaconName, const FString& BeaconIcon, const FName& BeaconWorld, FVector BeaconPos, AActor* NewBeaconObject, bool ShowOnHUD, bool ShowDistanceOnHud) {
    return 0;
}

void UBeaconManager::RegisterDungeonExit(FVector Position, FName UID, bool Disable) {
}

void UBeaconManager::RegisterDungeonEntrance(const FString& DungeonName, FVector Position, float ZRot, FVector BeaconPosition, int32 EntranceIndex) {
}

void UBeaconManager::OnSaveGameLoaded() {
}

void UBeaconManager::OnRevelioStart(float RevelioViewMeters) {
}

void UBeaconManager::OnRevelioEnd() {
}

void UBeaconManager::OnNewGame() {
}

void UBeaconManager::GetDungeonReqirementsByName(const FString& DungeonName, TArray<FText>& RequiredSpells, TArray<FText>& CompletionSpells) {
}

UBeaconInfo* UBeaconManager::GetBeaconByHandleBP(int32 ObjectHandle) {
    return NULL;
}

UBeaconManager* UBeaconManager::Get() {
    return NULL;
}

UBeaconManager::UBeaconManager() {
}

