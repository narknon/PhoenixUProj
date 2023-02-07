#include "StatsManager.h"

class UStatsManager;

void UStatsManager::UpdateStat(const FName Key, const int32 Delta) {
}

bool UStatsManager::StatExists(const FName Key) {
    return false;
}

void UStatsManager::SetStatBit(const FName Key, const int32 bit) {
}

void UStatsManager::SetStat(const FName Key, const int32 Value) {
}

int32 UStatsManager::ReadStat(const FName Key) {
    return 0;
}

int32 UStatsManager::ReadSetBitCount(const FName Key) {
    return 0;
}

bool UStatsManager::ReadBitSet(const FName Key, const int32 bit) {
    return false;
}

void UStatsManager::OnGameToBeSaved() {
}

FName UStatsManager::GetStatName(const FStatList StatList) {
    return NAME_None;
}

UStatsManager* UStatsManager::Get() {
    return NULL;
}

void UStatsManager::GameStatSet(const FString& StatKey, int32 StatValue) {
}

void UStatsManager::GameStatGet(const FString& StatKey) {
}

bool UStatsManager::DeleteStat(FName Key) {
    return false;
}

void UStatsManager::ClearStatBit(const FName Key, const int32 bit) {
}

bool UStatsManager::AddNewStat(FName StatID, const int32 Value) {
    return false;
}

UStatsManager::UStatsManager() {
}

