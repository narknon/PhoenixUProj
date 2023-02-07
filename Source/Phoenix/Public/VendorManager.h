#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UnavailableIconInfo.h"
#include "VendorBroomPreviewClassLoadedDelegate.h"
#include "VendorInfo.h"
#include "VendorManager.generated.h"

class UDataTable;
class UVendorManager;

UCLASS(Blueprintable)
class UVendorManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVendorBroomPreviewClassLoaded VendorBroomPreviewClassLoaded;
    
private:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* VendorBroomPreviewDataTable;
    
public:
    UVendorManager();
    UFUNCTION(BlueprintCallable, Exec)
    static void ReloadVendorStock(FName VendorID);
    
    UFUNCTION(BlueprintCallable)
    static void RefreshVendorStockIfNeeded(FName Vendor);
    
    UFUNCTION(BlueprintCallable)
    static void RefreshVendorStock(FName Vendor);
    
    UFUNCTION(BlueprintCallable)
    void LoadVendorBroomPreviewActorClass(const FName BroomID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FUnavailableIconInfo> GetUnavailableVendorItems(FName VendorID);
    
    UFUNCTION(BlueprintCallable)
    static UVendorManager* Get();
    
private:
    UFUNCTION(BlueprintCallable)
    static TArray<FVendorInfo> BP_GetVendorsSellingItem(FName ItemId);
    
};

