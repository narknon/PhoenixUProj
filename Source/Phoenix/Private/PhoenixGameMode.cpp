#include "PhoenixGameMode.h"


void APhoenixGameMode::YeeTest() {
}

void APhoenixGameMode::VCGetContents(const FString& ContainerID) {
}

void APhoenixGameMode::UnregisterInterestPointActor(const FString& ActorName) {
}

void APhoenixGameMode::SetProgrammaticPlayerStartInfo(const FVector& InLocation, const FRotator& InRotation, bool bForceUse) {
}

void APhoenixGameMode::SetLocale(const FString& LocaleString) {
}

void APhoenixGameMode::RemoveInstancedStaticMeshCollision(UInstancedStaticMeshComponent* InstancedMeshComponent, int32 InstanceIndex) {
}

void APhoenixGameMode::RegisterInterestPointActor(const FString& InActorName, float InSpawnX, float InSpawnY, float InSpawnZ, bool bSpawnNewActor) {
}

bool APhoenixGameMode::PlayerStartedAtProgrammaticLocation() const {
    return false;
}

void APhoenixGameMode::OpenLevelByReference(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level, bool bAbsolute, const FString& OPTIONS) {
}

void APhoenixGameMode::LootDrop(const FString& LootCategoryID, int32 Level) {
}

ULevelStreaming* APhoenixGameMode::GetStreamingLevelAva(const UObject* WorldContextObject, FName PackageName) {
    return NULL;
}

FString APhoenixGameMode::GetPlayerStartTag() const {
    return TEXT("");
}

APhoenixGameMode* APhoenixGameMode::GetPhoenixGameMode() {
    return NULL;
}

FString APhoenixGameMode::GetOptions() {
    return TEXT("");
}

void APhoenixGameMode::GameStartMission() {
}

void APhoenixGameMode::GameFinishMission() {
}

void APhoenixGameMode::GameDBImport(const FString& ImportFilename) {
}

void APhoenixGameMode::GameDBExport(const FString& ExportFilename) {
}

void APhoenixGameMode::GameAbortMission() {
}

void APhoenixGameMode::Dbg_ShowHUD() {
}

void APhoenixGameMode::Dbg_HideHUD() {
}

void APhoenixGameMode::ClearForceUseProgrammaticPlayerStart() {
}

void APhoenixGameMode::AsyncLoadAssetList(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UObject>>& AssetsToStream, int32& UniqueId) {
}

APhoenixGameMode::APhoenixGameMode() {
    this->ProgrammaticPlayerStart = NULL;
}

