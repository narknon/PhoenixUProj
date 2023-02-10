#include "PhoenixGameInstance.h"

void UPhoenixGameInstance::UpdateSaveSpawnLocationEx(const FVector PlayerPostion, const FRotator PlayerOrientation) {
}

void UPhoenixGameInstance::UpdateSaveSpawnLocation() {
}

void UPhoenixGameInstance::UpdateChallengeSpawnLocation() {
}

void UPhoenixGameInstance::StartNewGame(bool bInIsIntro) {
}

void UPhoenixGameInstance::SetSaveSpawnLocationToPlayerStart(APlayerStart* InPlayerStart) {
}

void UPhoenixGameInstance::SetPlayingFromFrontend() {
}

void UPhoenixGameInstance::SetPlayingFromDeveloperMenu(bool bDeveloperMenu) {
}

void UPhoenixGameInstance::SetPlayingDeveloperOverland(bool DeveloperOverland) {
}

void UPhoenixGameInstance::SetPlayingDemoBuild() {
}

void UPhoenixGameInstance::SetCurrentLoadingScreenLocationByLevelName(const FName LevelName, const FString& PlayerStartTag) {
}

void UPhoenixGameInstance::SetCurrentLoadingScreenLocation(const ELoadingScreenLocation Location) {
}

bool UPhoenixGameInstance::SaveGameOptions() {
    return false;
}

bool UPhoenixGameInstance::PlayOverland() {
    return false;
}

void UPhoenixGameInstance::PhoenixOpenLevelBySoftObjectPtr(const UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level, bool bAbsolute, const FString& OPTIONS) {
}

void UPhoenixGameInstance::PhoenixOpenLevel(const UObject* WorldContextObject, FName LevelName, bool bAbsolute, const FString& OPTIONS) {
}

void UPhoenixGameInstance::OnSaveGameLoaded() {
}

void UPhoenixGameInstance::OnDBVersionCheck(const int32 SaveVersion, const int32 SaveChangeList) {
}

void UPhoenixGameInstance::OnAcceptEULA(bool Update) {
}

void UPhoenixGameInstance::OnAboutToSaveGame() {
}

bool UPhoenixGameInstance::NewGame(bool bInIsIntro) {
    return false;
}

bool UPhoenixGameInstance::LoadGameOptions() {
    return false;
}

bool UPhoenixGameInstance::LoadGame(const FString& SlotName, int32 SlotIndex) {
    return false;
}

void UPhoenixGameInstance::LevelShutdown() {
}

void UPhoenixGameInstance::HoldPlayerUntilColliding(bool bFromHoverDrone) {
}

bool UPhoenixGameInstance::HasLoadSaveData() {
    return false;
}

FRotator UPhoenixGameInstance::GetSaveRotation() const {
    return FRotator{};
}

FVector UPhoenixGameInstance::GetSavePosition() const {
    return FVector{};
}

FString UPhoenixGameInstance::GetSaveGameWorld() const {
    return TEXT("");
}

FVector UPhoenixGameInstance::GetSafePlayerPosition() {
    return FVector{};
}

bool UPhoenixGameInstance::GetPlayingFromFrontend() {
    return false;
}

bool UPhoenixGameInstance::GetPlayingFromDeveloperMenu() {
    return false;
}

bool UPhoenixGameInstance::GetPlayingDeveloperOverland() const {
    return false;
}

bool UPhoenixGameInstance::GetPlayingDemoBuild() {
    return false;
}

FVector UPhoenixGameInstance::GetPlayerPosition() {
    return FVector{};
}

APawn* UPhoenixGameInstance::GetPlayerPawn() {
    return NULL;
}

FRotator UPhoenixGameInstance::GetPlayerOrientation() {
    return FRotator{};
}

UPhoenixGameInstance* UPhoenixGameInstance::GetPhoenixGameInstancePure() {
    return NULL;
}

UPhoenixGameInstance* UPhoenixGameInstance::GetPhoenixGameInstance() {
    return NULL;
}

FString UPhoenixGameInstance::GetCurrentWorldName() {
    return TEXT("");
}

ELoadingScreenLocation UPhoenixGameInstance::GetCurrentLoadingScreenLocation() {
    return ELoadingScreenLocation::LSL_None;
}

void UPhoenixGameInstance::GameSaveHorcrux(const FString& SaveLabel) {
}

void UPhoenixGameInstance::GameLoadImportedHorcruxToNewCharacter(int32 DestCharacterID) {
}

void UPhoenixGameInstance::GameLoadImportedHorcrux() {
}

void UPhoenixGameInstance::GameLoadHorcruxToNewCharacter(const FString& SaveLabel, int32 DestCharacterID) {
}

void UPhoenixGameInstance::GameLoadHorcrux(const FString& SaveLabel) {
}

void UPhoenixGameInstance::GameLoadCloudSave(const FString& SlotName, bool bNewCharacter, int32 DestCharacterID) {
}

void UPhoenixGameInstance::ForceSeasonUpdate(ESeasonEnum NewSeason) {
}

void UPhoenixGameInstance::FadeReset() {
}

void UPhoenixGameInstance::FadeOutToColor(FColor inFadeColor) {
}

void UPhoenixGameInstance::FadeOut() {
}

void UPhoenixGameInstance::FadeIn() {
}

ULevel* UPhoenixGameInstance::DetectLevelBelowCamera(const UObject* WorldContextObject) {
    return NULL;
}

bool UPhoenixGameInstance::ContinueGame() {
    return false;
}

void UPhoenixGameInstance::ClearPlayerHold() {
}

void UPhoenixGameInstance::ClearChallengeSpawnLocationFlag() {
}

bool UPhoenixGameInstance::AutoSaveGameData(const EAutoSaveReason Type) {
    return false;
}

UPhoenixGameInstance::UPhoenixGameInstance() {
    this->RespawnReason = ERespawnReason::None;
    this->FastTravelManagerClass = NULL;
    this->bAllowHoldPlayerUntilColliding = true;
}

