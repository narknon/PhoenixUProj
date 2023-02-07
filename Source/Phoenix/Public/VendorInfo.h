#pragma once
#include "CoreMinimal.h"
#include "VendorInfo.generated.h"

USTRUCT(BlueprintType)
struct FVendorInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VendorID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VendorLocationID;
    
    PHOENIX_API FVendorInfo();
};

