#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarExpression.generated.h"

class UExposureExpressionsScalarValue;

USTRUCT(BlueprintType)
struct FExposureExpressionsScalarExpression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Expression;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsScalarExpression();
};

