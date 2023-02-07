#include "SpellManagerBPInterface.h"

void USpellManagerBPInterface::SetTargetingSpell(int32 SpellLoadoutIndex, int32 SpellIndex, FName SpellName) {
}

void USpellManagerBPInterface::SetSpellFinisher(FName SpellName) {
}

void USpellManagerBPInterface::SetSpell(int32 LoadoutIndex, int32 SpellIndex, FName SpellName) {
}

void USpellManagerBPInterface::SetOverrideSpellLevel(int32 SpellLevel) {
}

void USpellManagerBPInterface::SetFinisherSpell(FName SpellName) {
}

void USpellManagerBPInterface::SetCurrentSpellLoadoutIndex(int32 LayoutIndex) {
}

bool USpellManagerBPInterface::IsUnlocked(FName SpellLockName) {
    return false;
}

void USpellManagerBPInterface::GetTargetingSpells(TArray<FName>& SpellNames) {
}

TMap<FName, FSpellUpgradeState> USpellManagerBPInterface::GetSpellUpgradeMap() {
    return TMap<FName, FSpellUpgradeState>();
}

TArray<FName> USpellManagerBPInterface::GetSpellsInCategory(ESpellCategory Category, bool IncludeLocked) {
    return TArray<FName>();
}

bool USpellManagerBPInterface::GetSpellsFinisher(TArray<FName>& SpellNames) {
    return false;
}

bool USpellManagerBPInterface::GetSpellsByGroup(int32 LoadoutIndex, TArray<FName>& SpellNames) {
    return false;
}

TArray<FString> USpellManagerBPInterface::GetSpellGroupNames() {
    return TArray<FString>();
}

FName USpellManagerBPInterface::GetSpellFinisher() {
    return NAME_None;
}

FName USpellManagerBPInterface::GetSpellCategory(const FString& SpellName) {
    return NAME_None;
}

void USpellManagerBPInterface::GetSpell(int32 SpellLoadOut, int32 SpellIndex, FName& SpellName) {
}

void USpellManagerBPInterface::GetFinishingSpells(TArray<FName>& SpellNames) {
}

int32 USpellManagerBPInterface::GetCurrentSpellLoadoutIndex() {
    return 0;
}

bool USpellManagerBPInterface::GetCurrentSpellLoadout(TArray<FName>& SpellNames) {
    return false;
}

int32 USpellManagerBPInterface::GetCurrentSpellIndex() {
    return 0;
}

int32 USpellManagerBPInterface::GetAvailableSpellCount(bool IncludeLocked) {
    return 0;
}

USpellManagerBPInterface::USpellManagerBPInterface() {
    this->NumLoadouts = 3;
    this->SpellsPerLoadout = 9;
}

