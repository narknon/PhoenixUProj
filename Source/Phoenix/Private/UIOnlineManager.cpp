#include "UIOnlineManager.h"

class UPopupScreen;
class UTexture2DDynamic;
class UUIOnlineManager;

void UUIOnlineManager::WBPNStartSilentLogin() {
}

void UUIOnlineManager::WBPNStartLogin(const bool deviceFlow, const FString& UserName, const FString& password) {
}

void UUIOnlineManager::WBPNRequestAccountInfo() {
}

void UUIOnlineManager::WBPNPollForWWLink() {
}

void UUIOnlineManager::WBPNGenerateDeviceToken(bool bPollLogin) {
}

void UUIOnlineManager::WBPNExitDeviceFlow(bool bContinuePolling) {
}

void UUIOnlineManager::WBPNCheckLinkStatus() {
}

void UUIOnlineManager::UpdateNetworkNotification() {
}

void UUIOnlineManager::UpdateFullGameNotInstalledMessage() {
}

void UUIOnlineManager::ShowPlatformLogo() {
}

void UUIOnlineManager::ShowFullGameNotInstalledMessage() {
}

void UUIOnlineManager::SendWizardingWorldData(const FString& AttributeKey, const FString& AttributeValue, const bool Update) {
}

void UUIOnlineManager::RetryConnection() {
}

void UUIOnlineManager::RetrieveWizardingWorldData(bool bUpdateOnFailure) {
}

void UUIOnlineManager::ResetWBPNLogin() {
}

void UUIOnlineManager::RequestWizardWords() {
}

void UUIOnlineManager::RequestMOTD() {
}

void UUIOnlineManager::RequestEULA() {
}

void UUIOnlineManager::RefreshRichPresenceString() {
}

void UUIOnlineManager::QueryStoreReceipts() {
}

void UUIOnlineManager::QueryStoreOffers() {
}

void UUIOnlineManager::PurchaseDLC(const FString& OfferId) {
}

void UUIOnlineManager::OnFullGameNotInstalledMessageClosed(UPopupScreen* PopupScreen, int32 CompletionActionIndex) {
}

void UUIOnlineManager::OnControllerDisconnectedPopupClosed(UPopupScreen* PopupScreen, int32 CompletionActionIndex) {
}

bool UUIOnlineManager::IsNetworkConnected() {
    return false;
}

bool UUIOnlineManager::IsLoggedIn() const {
    return false;
}

bool UUIOnlineManager::IsHydraLoggedIn() {
    return false;
}

bool UUIOnlineManager::IsFullGameInstalled() {
    return false;
}

bool UUIOnlineManager::IsDay0PatchInstalled() {
    return false;
}

bool UUIOnlineManager::IsConnectedToOnlineServices() {
    return false;
}

void UUIOnlineManager::HidePlatformLogo() {
}

FString UUIOnlineManager::GetWWIDUsername() {
    return TEXT("");
}

TArray<FString> UUIOnlineManager::GetWizardWords() {
    return TArray<FString>();
}

FString UUIOnlineManager::GetWBPNUsername() {
    return TEXT("");
}

FString UUIOnlineManager::GetWBPNUrl() {
    return TEXT("");
}

FString UUIOnlineManager::GetWBPNUnlink() {
    return TEXT("");
}

FString UUIOnlineManager::GetWBPNShortcode() {
    return TEXT("");
}

UTexture2DDynamic* UUIOnlineManager::GetWBPNQRCode(const int32 texWidth, const int32 texHeight, const bool bUnlink) {
    return NULL;
}

EAccountLinkStatus UUIOnlineManager::GetWBPNLinkStatus() {
    return EAccountLinkStatus::NoOnlineConnection;
}

UUIOnlineManager* UUIOnlineManager::GetUIOnlineManagerPure() {
    return NULL;
}

void UUIOnlineManager::GetStoreState(FString& StoreState) {
}

void UUIOnlineManager::GetStoreOffers(TArray<FOnlineOfferStruct>& Offers) {
}

void UUIOnlineManager::GetProfileName(FString& ProfileName) {
}

TArray<FString> UUIOnlineManager::GetPendingRewardNotifications() {
    return TArray<FString>();
}

TArray<FMOTD> UUIOnlineManager::GetMOTD() {
    return TArray<FMOTD>();
}

FString UUIOnlineManager::GetHydraID() {
    return TEXT("");
}

float UUIOnlineManager::GetFullGameInstallCompletionPercent() {
    return 0.0f;
}

FString UUIOnlineManager::GetExternalConfig(const FString& LinkType) {
    return TEXT("");
}

FText UUIOnlineManager::GetEULA() {
    return FText::GetEmpty();
}

UUIOnlineManager* UUIOnlineManager::Get() {
    return NULL;
}

void UUIOnlineManager::ForceRichPresenceString(const FString& RichPresenceString) {
}

void UUIOnlineManager::DismissRewardNotification(const FString& RewardID) {
}

UUIOnlineManager::UUIOnlineManager() {
    this->ControllerDisconnectPopup = NULL;
    this->FullGameNotInstalledPopup = NULL;
    this->LoginStatusChangedPopup = NULL;
}

