#include "PerksTree.h"

class UPerksTree;

bool UPerksTree::UpgradePerk(const FString& PerkID) {
    return false;
}

bool UPerksTree::UpdatePerkPoints(int32 Amount) {
    return false;
}

void UPerksTree::ResetPerks() {
}

void UPerksTree::RemovePerk(const FString& InPerkID) {
}

FPerkTreeEntry UPerksTree::RefreshDataForSlot(const FString& PerkCategory, int32 Row, int32 Column) {
    return FPerkTreeEntry{};
}

bool UPerksTree::PurchasePerk(const FString& PerkID) {
    return false;
}

void UPerksTree::PerkUpdatePoints(int32 Amount) {
}

void UPerksTree::PerkShowPurchasedCount() {
}

void UPerksTree::PerkShowPoints() {
}

void UPerksTree::PerkSetLevel(const FString& PerkID, int32 Level) {
}

void UPerksTree::PerkResetAllPerks() {
}

void UPerksTree::PerkPurchase(const FString& PerkID) {
}

void UPerksTree::PerkIsUpgradeable(const FString& PerkID) {
}

void UPerksTree::PerkIsAvailable(const FString& PerkID) {
}

void UPerksTree::PerkIsActive(const FString& PerkID) {
}

void UPerksTree::PerkCurriculumRefresh(const FString& Curriculum, int32 Year) {
}

void UPerksTree::PerkActivateAllInCategory(const FString& Category) {
}

void UPerksTree::PerkActivateAll() {
}

void UPerksTree::PerkActivate(const FString& PerkID) {
}

void UPerksTree::OnSaveGameLoaded() {
}

bool UPerksTree::IsPerkUpgradeable(const FString& PerkID) {
    return false;
}

bool UPerksTree::IsPerkAvailable(const FString& PerkID) {
    return false;
}

int32 UPerksTree::GetTotalPerks(const FString& CategoryID) {
    return 0;
}

int32 UPerksTree::GetPurchasedPerkCount(const FString& CategoryID) {
    return 0;
}

EPerkState UPerksTree::GetPerkState(const FString& PerkID) {
    return EPerkState::PERK_UNAVAILABLE;
}

int32 UPerksTree::GetPerkPoints() {
    return 0;
}

int32 UPerksTree::GetPerkLevel(const FString& PerkID) {
    return 0;
}

TArray<FPerkTreeEntry> UPerksTree::GetAllPerks(bool UIDisplayOnly, const FString& CategoryID) {
    return TArray<FPerkTreeEntry>();
}

UPerksTree* UPerksTree::Get() {
    return NULL;
}

UPerksTree::UPerksTree() {
}

