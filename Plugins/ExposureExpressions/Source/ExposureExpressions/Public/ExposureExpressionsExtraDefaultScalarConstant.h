#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraDefault.h"
#include "ExposureExpressionsExtraDefaultScalarConstant.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraDefaultScalarConstant : public FExposureExpressionsExtraDefault {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraDefaultScalarConstant();
};

