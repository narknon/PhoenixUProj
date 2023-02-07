#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraDefault.h"
#include "ExposureExpressionsExtraDefaultExposureConstant.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraDefaultExposureConstant : public FExposureExpressionsExtraDefault {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraDefaultExposureConstant();
};

