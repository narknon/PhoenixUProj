#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EPerkState.h"
#include "PerkTreeEntry.h"
#include "PerksTree.generated.h"

class UPerksTree;

UCLASS(Blueprintable)
class UPerksTree : public UObject {
    GENERATED_BODY()
public:
    UPerksTree();
    UFUNCTION(BlueprintCallable)
    bool UpgradePerk(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePerkPoints(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    static void ResetPerks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void RemovePerk(const FString& InPerkID);
    
    UFUNCTION(BlueprintCallable)
    static FPerkTreeEntry RefreshDataForSlot(const FString& PerkCategory, int32 Row, int32 Column);
    
    UFUNCTION(BlueprintCallable)
    bool PurchasePerk(const FString& PerkID);
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void PerkUpdatePoints(int32 Amount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkShowPurchasedCount();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkShowPoints();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkSetLevel(const FString& PerkID, int32 Level);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkResetAllPerks();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkPurchase(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkIsUpgradeable(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkIsAvailable(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkIsActive(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkCurriculumRefresh(const FString& Curriculum, int32 Year);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkActivateAllInCategory(const FString& Category);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkActivateAll();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void PerkActivate(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    bool IsPerkUpgradeable(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable)
    bool IsPerkAvailable(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetTotalPerks(const FString& CategoryID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetPurchasedPerkCount(const FString& CategoryID);
    
    UFUNCTION(BlueprintCallable)
    EPerkState GetPerkState(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPerkPoints();
    
    UFUNCTION(BlueprintCallable)
    int32 GetPerkLevel(const FString& PerkID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FPerkTreeEntry> GetAllPerks(bool UIDisplayOnly, const FString& CategoryID);
    
    UFUNCTION(BlueprintCallable)
    static UPerksTree* Get();
    
};

