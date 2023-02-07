#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoxBoundsInfo.generated.h"

USTRUCT(BlueprintType)
struct FBoxBoundsInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Center;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Extent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    LERPVOLUMES_API FBoxBoundsInfo();
};

