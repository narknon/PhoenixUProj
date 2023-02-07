#pragma once
#include "CoreMinimal.h"
#include "RegionHeightData.generated.h"

USTRUCT(BlueprintType)
struct FRegionHeightData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RegionHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowBuffer;
    
    PHOENIX_API FRegionHeightData();
};

