#pragma once
#include "CoreMinimal.h"
#include "CullDistanceMinMax.generated.h"

USTRUCT(BlueprintType)
struct FCullDistanceMinMax {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Min;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Max;
    
    PHOENIX_API FCullDistanceMinMax();
};

