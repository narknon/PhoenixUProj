#include "ExperienceManager.h"



void UExperienceManager::SetLevelBounds(const int32 i_level, int32& o_startPoints, int32& o_endPoints) {
}

void UExperienceManager::SetExperienceLevel(int32 NewLevel) {
}

void UExperienceManager::OnSaveGameLoaded() {
}

void UExperienceManager::OnNewGame(const UObject* Caller, const bool IsInIntro) {
}

void UExperienceManager::OnGameToBeSaved() {
}

int32 UExperienceManager::GetExperiencePoints() {
    return 0;
}

int32 UExperienceManager::GetExperienceLevelStartPoints() {
    return 0;
}

int32 UExperienceManager::GetExperienceLevelEndPoints() {
    return 0;
}

int32 UExperienceManager::GetExperienceLevel() {
    return 0;
}

UExperienceManager* UExperienceManager::Get() {
    return NULL;
}

void UExperienceManager::GainExperienceByAction(const FString& ExperienceAction) {
}

void UExperienceManager::AddExperience(const int32 Points, const FString& Source, const FString& source_detail) {
}

UExperienceManager::UExperienceManager() {
}

