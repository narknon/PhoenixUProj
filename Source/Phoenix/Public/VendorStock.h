#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VendorStock.generated.h"

UCLASS(Blueprintable)
class UVendorStock : public UObject {
    GENERATED_BODY()
public:
    UVendorStock();
    UFUNCTION(BlueprintCallable)
    void RefreshVendor(FName Vendor);
    
    UFUNCTION(BlueprintCallable)
    void RefreshAllVendors();
    
};

