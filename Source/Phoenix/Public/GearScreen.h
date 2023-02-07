#pragma once
#include "CoreMinimal.h"
#include "EGearSlotIDEnum.h"
#include "GearItemID.h"
#include "InventoryResult.h"
#include "RPGUIInfo.h"
#include "TabPageWidget.h"
#include "GearScreen.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class UGearScreen : public UTabPageWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* MenuCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* WandActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* BroomProxyActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* MountActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowAppearanceGear;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsAppearanceInventory;
    
public:
    UGearScreen();
protected:
    UFUNCTION(BlueprintCallable)
    bool UnequipGearItem(EGearSlotIDEnum GearSlot, FGearItemID& NewGearItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGearItemID MakeGearIdForAppearance(FName GearID, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerOnMount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerOnBroom();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetUnlockedAppearanceGear(EGearSlotIDEnum SlotID, TArray<FString>& OutCostumes, TArray<FString>& OutGeneral);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FInventoryResult> GetSortedTools(FName ActiveHolderID, FName StorageHolderID);
    
public:
    UFUNCTION(BlueprintCallable)
    TArray<FRPGUIInfo> GetActiveBuffData();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool EquipGearItem(FGearItemID GearItemID, FGearItemID& NewGearItemId);
    
};

