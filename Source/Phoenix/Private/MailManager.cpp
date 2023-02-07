#include "MailManager.h"

class UMailManager;
class UStationComponent;

void UMailManager::UpdateMailArchiveAndDeleteBP(const FString& MailKey, const FString& sender, bool& o_canArchive, bool& o_canDelete) {
}

bool UMailManager::StationKnownByMailManagerBP(UStationComponent* Station) {
    return false;
}

void UMailManager::OnSaveGameLoaded() {
}

void UMailManager::OnNewGame() {
}

void UMailManager::MailUIEventBP(const bool bStart, const TEnumAsByte<EMailType> mailType) {
}

void UMailManager::HandleMailUIButtonBP(const int32 Button, const FString& MailKey, const FString& sender, const bool bFromArchive, bool& o_bMailListChanged) {
}

int32 UMailManager::GetUnreadMailCountBP() {
    return 0;
}

void UMailManager::GetRadiantTaskTextBP(TArray<FString>& o_iconNames, TArray<int32>& o_taskQuantities) {
}

void UMailManager::GetRadiantRewardIconsBP(TArray<FString>& o_rewardIcons) {
}

bool UMailManager::GetMailOwlVisibilityBP() {
    return false;
}

void UMailManager::GetMailItemsBP(const bool bFromArchive, TArray<FUIMailInfo>& MailInfo) {
}

TEnumAsByte<EBulletinBoardType> UMailManager::GetBulletinBoardTypeBP() {
    return BULLETIN_BOARD_TYPE_HOGWARTS;
}

void UMailManager::GetBulletinBoardTextBP(TArray<int32>& o_mailIndexes, TArray<FString>& o_senders, TArray<bool>& o_acceptRadiantVisibles, TArray<FString>& o_descriptions) {
}

UMailManager* UMailManager::Get() {
    return NULL;
}

void UMailManager::BulletinItemClickedBP(const int32 ItemIndex, const bool bRadiantVisible) {
}

void UMailManager::AcceptBulletinBoardRadiantMissionBP() {
}

UMailManager::UMailManager() {
}

