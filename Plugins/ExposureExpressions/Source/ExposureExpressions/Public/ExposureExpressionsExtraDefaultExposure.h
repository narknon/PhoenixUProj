#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraDefault.h"
#include "ExposureExpressionsExtraDefaultExposure.generated.h"

class UExposureExpressionsExposureValue;

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraDefaultExposure : public FExposureExpressionsExtraDefault {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* DefaultExpression;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraDefaultExposure();
};

