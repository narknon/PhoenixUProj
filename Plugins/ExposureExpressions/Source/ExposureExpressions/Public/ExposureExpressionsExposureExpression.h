#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureExpression.generated.h"

class UExposureExpressionsExposureValue;

USTRUCT(BlueprintType)
struct FExposureExpressionsExposureExpression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* Expression;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExposureExpression();
};

