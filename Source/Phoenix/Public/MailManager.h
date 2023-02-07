#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EBulletinBoardType.h"
#include "EMailType.h"
#include "MailEntry.h"
#include "UIMailInfo.h"
#include "MailManager.generated.h"

class UMailManager;
class UStationComponent;

UCLASS(Blueprintable)
class UMailManager : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMailAvailableDelegate, FMailEntry, Entry, int32, DisplayPriority);
    
    UMailManager();
    UFUNCTION(BlueprintCallable)
    static void UpdateMailArchiveAndDeleteBP(const FString& MailKey, const FString& sender, bool& o_canArchive, bool& o_canDelete);
    
    UFUNCTION(BlueprintCallable)
    static bool StationKnownByMailManagerBP(UStationComponent* Station);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
public:
    UFUNCTION(BlueprintCallable)
    static void MailUIEventBP(const bool bStart, const TEnumAsByte<EMailType> mailType);
    
    UFUNCTION(BlueprintCallable)
    static void HandleMailUIButtonBP(const int32 Button, const FString& MailKey, const FString& sender, const bool bFromArchive, bool& o_bMailListChanged);
    
    UFUNCTION(BlueprintCallable)
    int32 GetUnreadMailCountBP();
    
    UFUNCTION(BlueprintCallable)
    static void GetRadiantTaskTextBP(TArray<FString>& o_iconNames, TArray<int32>& o_taskQuantities);
    
    UFUNCTION(BlueprintCallable)
    static void GetRadiantRewardIconsBP(TArray<FString>& o_rewardIcons);
    
    UFUNCTION(BlueprintCallable)
    static bool GetMailOwlVisibilityBP();
    
    UFUNCTION(BlueprintCallable)
    static void GetMailItemsBP(const bool bFromArchive, TArray<FUIMailInfo>& MailInfo);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EBulletinBoardType> GetBulletinBoardTypeBP();
    
    UFUNCTION(BlueprintCallable)
    static void GetBulletinBoardTextBP(TArray<int32>& o_mailIndexes, TArray<FString>& o_senders, TArray<bool>& o_acceptRadiantVisibles, TArray<FString>& o_descriptions);
    
    UFUNCTION(BlueprintCallable)
    static UMailManager* Get();
    
    UFUNCTION(BlueprintCallable)
    static void BulletinItemClickedBP(const int32 ItemIndex, const bool bRadiantVisible);
    
    UFUNCTION(BlueprintCallable)
    static void AcceptBulletinBoardRadiantMissionBP();
    
};

