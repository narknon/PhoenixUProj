#include "InfirmaryManager.h"

class UInfirmaryManager;

void UInfirmaryManager::OnSaveGameLoaded() {
}

void UInfirmaryManager::OnNewGame() {
}

void UInfirmaryManager::OnGameToBeSaved() {
}

bool UInfirmaryManager::IsStudentIn(const FString& UniqueId) {
    return false;
}

void UInfirmaryManager::HourlyCheck(const FTimeEvent& InTimeEvent) {
}

void UInfirmaryManager::GetStudents(TArray<FString>& OutStudents) {
}

UInfirmaryManager* UInfirmaryManager::Get() {
    return NULL;
}

void UInfirmaryManager::AddStudent(const FString& UniqueId, int64 SecondsInTheInfirmary, EInfirmaryPriority Priority) {
}

UInfirmaryManager::UInfirmaryManager() {
}

