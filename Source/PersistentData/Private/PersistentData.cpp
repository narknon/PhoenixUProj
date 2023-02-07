#include "PersistentData.h"

class UPersistentData;

bool UPersistentData::UpdatePlayableCharacterVoice(int32 CharacterID, const FString& CharacterVoice) {
    return false;
}

bool UPersistentData::UpdatePlayableCharacterPronoun(int32 CharacterID, const FString& CharacterPronoun) {
    return false;
}

bool UPersistentData::UpdatePlayableCharacterPresets(int32 CharacterID, TArray<FName> CharacterPresets) {
    return false;
}

bool UPersistentData::UpdatePlayableCharacterName(int32 CharacterID, const FString& CharacterName) {
    return false;
}

bool UPersistentData::UpdatePlayableCharacterLevel(int32 CharacterID, int32 CharacterLevel) {
    return false;
}

bool UPersistentData::UpdatePlayableCharacterHouse(int32 CharacterID, const FString& CharacterHouse) {
    return false;
}

bool UPersistentData::UpdatePlayableCharacterGender(int32 CharacterID, const FString& CharacterGender) {
    return false;
}

bool UPersistentData::UpdatePlayableCharacterClothes(int32 CharacterID, TArray<FName> CharacterClothes, const FString& AllGearTags) {
    return false;
}

bool UPersistentData::SaveGameDataOfType(ESaveType SaveType, int32 CharacterID, const FString& LocationName, const FString& MissionData, bool bCollectSaveData) {
    return false;
}

bool UPersistentData::SaveGameDataInSlot(const FString& SlotName, ESaveType SaveType, int32 CharacterID, const FString& LocationName, const FString& MissionData, bool bCollectSaveData, const FString& CloudLabel) {
    return false;
}

bool UPersistentData::RemoveSaveInSlot(const FString& SlotName, int32 CharacterID) {
    return false;
}

bool UPersistentData::RemovePlayableCharacter(int32 CharacterID, bool bSaveFileListAsync) {
    return false;
}

bool UPersistentData::RemoveAllSavesForCharacter(int32 CharacterID) {
    return false;
}

bool UPersistentData::RemoveAllSaveData() {
    return false;
}

void UPersistentData::OnCrossGenSaveDataLoaded(bool Result) {
}

bool UPersistentData::LoadLastSaveOfType(ESaveType SaveType, int32 CharacterID) {
    return false;
}

bool UPersistentData::LoadGameDataInSlot(const FString& SlotName, int32 CharacterID) {
    return false;
}

bool UPersistentData::LoadCrossGenSaveDataInSlot(const FString& SlotName, const FString& OldSlotName) {
    return false;
}

void UPersistentData::LoadCrossGenSaveData(int32 fromCharacterIndex, int32 toCharacterIndex, bool SaveFileList) {
}

void UPersistentData::LoadAllCrossGenSaveData() {
}

bool UPersistentData::HasEverLaunchedGame() {
    return false;
}

bool UPersistentData::HasCreatedPlayableCharacter() {
    return false;
}

bool UPersistentData::HasCompletedIntro() {
    return false;
}

bool UPersistentData::GetWizardingWorldData(const FString& Attribute, FString& OutValue) {
    return false;
}

FCharacterSaveGameInfo UPersistentData::GetPlayableCharacter(int32 CharacterID) {
    return FCharacterSaveGameInfo{};
}

FCharacterSaveGameInfo UPersistentData::GetLastLoadedPlayableCharacter() {
    return FCharacterSaveGameInfo{};
}

bool UPersistentData::GetIsPlayableCharacterUsed(int32 CharacterID) {
    return false;
}

UPersistentData* UPersistentData::GetInstance() {
    return NULL;
}

uint8 UPersistentData::GetDefaultDifficulty() {
    return 0;
}

int32 UPersistentData::GetCurrentPlayerID() {
    return 0;
}

FCharacterSaveGameInfo UPersistentData::GetCurrentPlayableCharacter() {
    return FCharacterSaveGameInfo{};
}

FString UPersistentData::GetCrossGenPlayableCharacterName(const FCharacterSaveGameInfo& CharacterInfo) {
    return TEXT("");
}

TArray<FCharacterSaveGameInfo> UPersistentData::GetCrossGenCharacterList() {
    return TArray<FCharacterSaveGameInfo>();
}

TArray<FSaveGameInfo> UPersistentData::GetAvailableCrossGenSaveData() {
    return TArray<FSaveGameInfo>();
}

TArray<FCharacterSaveGameInfo> UPersistentData::GetAllPlayableCharacters() {
    return TArray<FCharacterSaveGameInfo>();
}

void UPersistentData::GameUserSave(int32 CharacterID) {
}

void UPersistentData::GameTestSaveGameList(int32 CharacterID) {
}

void UPersistentData::GameRemoveSaveSlot(const FString& SlotName, int32 CharacterID) {
}

void UPersistentData::GameRemovePlayableCharacter(int32 CharacterID) {
}

void UPersistentData::GamePurgeAllSaveData() {
}

void UPersistentData::GameLogSaveGameList(int32 CharacterID) {
}

void UPersistentData::GameLogSaveDirList() {
}

void UPersistentData::GameLogPlayableCharacters() {
}

void UPersistentData::GameLoadLastUserSave(int32 CharacterID) {
}

void UPersistentData::GameLoadLastSave(int32 CharacterID) {
}

void UPersistentData::GameLoadLastAutoSave(int32 CharacterID) {
}

void UPersistentData::GameLoad(int32 CharacterID, const FString& SaveNameOverride) {
}

void UPersistentData::GameDBSave(const FString& SaveFileNameOverride) {
}

void UPersistentData::GameDBLoad(const FString& SaveFileNameOverride) {
}

void UPersistentData::GameCreatePlayableCharacter(const FString& CharacterName, const FString& CharacterHouse) {
}

void UPersistentData::GameAutoSave(int32 CharacterID) {
}

void UPersistentData::FlushAutoSaveCacheIfNecessary() {
}

bool UPersistentData::DoesCrossGenSaveDataExist() {
    return false;
}

void UPersistentData::CrossGenSaveDataLog() {
}

void UPersistentData::CrossGenSaveDataLoad(int32 fromCharacterIndex, int32 toCharacterIndex) {
}

int32 UPersistentData::CreatePlayableCharacter(const FString& CharacterName, const FString& CharacterHouse, const FString& CharacterUID, const FString& CharacterVoice, const FString& CharacterPronoun) {
    return 0;
}

void UPersistentData::CreateHorcruxSlot() {
}

void UPersistentData::CompletedIntro() {
}

bool UPersistentData::BP_SaveGame(const FString& LocationName) {
    return false;
}

bool UPersistentData::BP_DoesCharacterExistYet() {
    return false;
}

bool UPersistentData::BP_CreateCharacter(const FString& CharacterName, const FString& CharacterHouse) {
    return false;
}

bool UPersistentData::AsyncRemovePlayableCharacter(int32 CharacterID) {
    return false;
}

UPersistentData::UPersistentData() {
}

