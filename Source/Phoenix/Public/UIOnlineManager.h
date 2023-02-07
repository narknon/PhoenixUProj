#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MOTD.h"
#include "EAccountLinkStatus.h"
#include "OnFullGameNotInstalledPopupClosedDelegate.h"
#include "OnlineOfferStruct.h"
#include "UIOnlineManager.generated.h"

class UPopupScreen;
class UTexture2DDynamic;
class UUIOnlineManager;

UCLASS(Blueprintable)
class UUIOnlineManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFullGameNotInstalledPopupClosed OnFullGameNotInstalledPopupClosed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPopupScreen* ControllerDisconnectPopup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPopupScreen* FullGameNotInstalledPopup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPopupScreen* LoginStatusChangedPopup;
    
public:
    UUIOnlineManager();
    UFUNCTION(BlueprintCallable)
    void WBPNStartSilentLogin();
    
    UFUNCTION(BlueprintCallable)
    void WBPNStartLogin(const bool deviceFlow, const FString& UserName, const FString& password);
    
    UFUNCTION(BlueprintCallable)
    void WBPNRequestAccountInfo();
    
    UFUNCTION(BlueprintCallable)
    void WBPNPollForWWLink();
    
    UFUNCTION(BlueprintCallable)
    void WBPNGenerateDeviceToken(bool bPollLogin);
    
    UFUNCTION(BlueprintCallable)
    void WBPNExitDeviceFlow(bool bContinuePolling);
    
    UFUNCTION(BlueprintCallable)
    void WBPNCheckLinkStatus();
    
    UFUNCTION(BlueprintCallable)
    void UpdateNetworkNotification();
    
    UFUNCTION(BlueprintCallable)
    void UpdateFullGameNotInstalledMessage();
    
    UFUNCTION(BlueprintCallable)
    void ShowPlatformLogo();
    
    UFUNCTION(BlueprintCallable)
    void ShowFullGameNotInstalledMessage();
    
    UFUNCTION(BlueprintCallable)
    void SendWizardingWorldData(const FString& AttributeKey, const FString& AttributeValue, const bool Update);
    
    UFUNCTION(BlueprintCallable)
    void RetryConnection();
    
    UFUNCTION(BlueprintCallable)
    void RetrieveWizardingWorldData(bool bUpdateOnFailure);
    
    UFUNCTION(BlueprintCallable)
    void ResetWBPNLogin();
    
    UFUNCTION(BlueprintCallable)
    void RequestWizardWords();
    
    UFUNCTION(BlueprintCallable)
    void RequestMOTD();
    
    UFUNCTION(BlueprintCallable)
    void RequestEULA();
    
    UFUNCTION(BlueprintCallable)
    void RefreshRichPresenceString();
    
    UFUNCTION(BlueprintCallable)
    void QueryStoreReceipts();
    
    UFUNCTION(BlueprintCallable)
    void QueryStoreOffers();
    
    UFUNCTION(BlueprintCallable)
    void PurchaseDLC(const FString& OfferId);
    
    UFUNCTION(BlueprintCallable)
    void OnFullGameNotInstalledMessageClosed(UPopupScreen* PopupScreen, int32 CompletionActionIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnControllerDisconnectedPopupClosed(UPopupScreen* PopupScreen, int32 CompletionActionIndex);
    
    UFUNCTION(BlueprintCallable)
    bool IsNetworkConnected();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLoggedIn() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsHydraLoggedIn();
    
    UFUNCTION(BlueprintCallable)
    bool IsFullGameInstalled();
    
    UFUNCTION(BlueprintCallable)
    bool IsDay0PatchInstalled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectedToOnlineServices();
    
    UFUNCTION(BlueprintCallable)
    void HidePlatformLogo();
    
    UFUNCTION(BlueprintCallable)
    FString GetWWIDUsername();
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetWizardWords();
    
    UFUNCTION(BlueprintCallable)
    FString GetWBPNUsername();
    
    UFUNCTION(BlueprintCallable)
    FString GetWBPNUrl();
    
    UFUNCTION(BlueprintCallable)
    FString GetWBPNUnlink();
    
    UFUNCTION(BlueprintCallable)
    FString GetWBPNShortcode();
    
    UFUNCTION(BlueprintCallable)
    UTexture2DDynamic* GetWBPNQRCode(const int32 texWidth, const int32 texHeight, const bool bUnlink);
    
    UFUNCTION(BlueprintCallable)
    EAccountLinkStatus GetWBPNLinkStatus();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UUIOnlineManager* GetUIOnlineManagerPure();
    
    UFUNCTION(BlueprintCallable)
    void GetStoreState(FString& StoreState);
    
    UFUNCTION(BlueprintCallable)
    void GetStoreOffers(TArray<FOnlineOfferStruct>& Offers);
    
    UFUNCTION(BlueprintCallable)
    void GetProfileName(FString& ProfileName);
    
    UFUNCTION(BlueprintCallable)
    TArray<FString> GetPendingRewardNotifications();
    
    UFUNCTION(BlueprintCallable)
    TArray<FMOTD> GetMOTD();
    
    UFUNCTION(BlueprintCallable)
    FString GetHydraID();
    
    UFUNCTION(BlueprintCallable)
    float GetFullGameInstallCompletionPercent();
    
    UFUNCTION(BlueprintCallable)
    FString GetExternalConfig(const FString& LinkType);
    
    UFUNCTION(BlueprintCallable)
    FText GetEULA();
    
    UFUNCTION(BlueprintCallable)
    static UUIOnlineManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void ForceRichPresenceString(const FString& RichPresenceString);
    
    UFUNCTION(BlueprintCallable)
    void DismissRewardNotification(const FString& RewardID);
    
};

