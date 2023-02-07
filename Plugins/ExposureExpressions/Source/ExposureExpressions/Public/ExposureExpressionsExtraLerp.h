#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraLerp.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraLerp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Targets;
    
    FExposureExpressionsExtraLerp();
};

