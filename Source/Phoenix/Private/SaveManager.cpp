#include "SaveManager.h"

class USaveManager;

bool USaveManager::UserSaveGameData() {
    return false;
}

bool USaveManager::UpdateActiveCharacterProfilePresets(TArray<FName> CharacterPresets) {
    return false;
}

bool USaveManager::UpdateActiveCharacterProfileClothes(TArray<FName> CharacterClothes, const FString& AllGearTags) {
    return false;
}

void USaveManager::UnblockSaveGames() {
}

void USaveManager::SetPrimaryUserIndex(int32 Index) {
}

bool USaveManager::SetCurrentVoicePitch(int32 VoicePitch) {
    return false;
}

bool USaveManager::SetCurrentRigGender(const FString& RigGender) {
    return false;
}

bool USaveManager::SetCurrentGameDifficulty(EDifficulty Difficulty) {
    return false;
}

bool USaveManager::SaveCurrentVoicePitch(int32 VoicePitch) {
    return false;
}

bool USaveManager::ResetCurrentGameDifficulty() {
    return false;
}

void USaveManager::RemoveBlockRequest(const ESaveBlockReason Reason, const bool bRemoveAll) {
}

bool USaveManager::IsSaveGameBlocked() {
    return false;
}

bool USaveManager::IsAutoSaveGameBlocked(const EAutoSaveReason Reason) {
    return false;
}

int32 USaveManager::GetPrimaryUserIndex() {
    return 0;
}

int32 USaveManager::GetCurrentVoicePitch() {
    return 0;
}

bool USaveManager::GetCurrentGameDifficulty(EDifficulty& Difficulty) {
    return false;
}

TArray<FSaveGameInfo> USaveManager::GetAllUserEntries() {
    return TArray<FSaveGameInfo>();
}

TArray<FSaveGameInfo> USaveManager::GetAllSavesOfType_Unsorted_IncludeEmptyUserSaves(ESaveType SaveType, int32 PlayerId) {
    return TArray<FSaveGameInfo>();
}

TArray<FSaveGameInfo> USaveManager::GetAllSavesOfType(ESaveType SaveType, int32 PlayerId) {
    return TArray<FSaveGameInfo>();
}

TArray<FSaveGameInfo> USaveManager::GetAllAutoEntries() {
    return TArray<FSaveGameInfo>();
}

USaveManager* USaveManager::Get() {
    return NULL;
}

void USaveManager::ExecutePreGameSave() {
}

void USaveManager::ExecutePreGameLoad() {
}

void USaveManager::ExecutePostGameSave() {
}

void USaveManager::ExecutePostGameLoad() {
}

void USaveManager::ExecuteCombatEnds() {
}

void USaveManager::ExecuteCombatBegins() {
}

void USaveManager::DumpSaveGameBlocks() {
}

void USaveManager::ClearSaveGameBlocks() {
}

bool USaveManager::BP_DoesCharacterExistYet() {
    return false;
}

bool USaveManager::BP_CreateCharacter(const FString& CharacterName, const FString& CharacterHouse) {
    return false;
}

void USaveManager::BP_ContinuePrevSessionClock() {
}

bool USaveManager::BP_AutoSaveGame(EAutoSaveReason Reason) {
    return false;
}

void USaveManager::BlockSaveGames() {
}

bool USaveManager::AutoSaveGameData(const EAutoSaveReason Type, bool bCollectSaveData) {
    return false;
}

bool USaveManager::AutoSaveFlush(bool bAsynchronous) {
    return false;
}

void USaveManager::AddBlockRequest(const ESaveBlockReason Reason) {
}

USaveManager::USaveManager() {
}

