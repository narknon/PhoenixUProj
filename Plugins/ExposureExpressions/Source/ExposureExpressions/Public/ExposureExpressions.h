#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureExpression.h"
#include "ExposureExpressionsScalarExpression.h"
#include "ExposureExpressions.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> ExposureConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExposureExpression> ExposureExpressions;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> ScalarConstants;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsScalarExpression> ScalarExpressions;
    
    FExposureExpressions();
};

