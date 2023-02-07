#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraDefault.h"
#include "ExposureExpressionsExtraDefaultScalar.generated.h"

class UExposureExpressionsScalarValue;

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraDefaultScalar : public FExposureExpressionsExtraDefault {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* DefaultExpression;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraDefaultScalar();
};

