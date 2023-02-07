#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarExpressionName.h"
#include "ExposureExpressionsScalarValue.h"
#include "ExposureExpressionsGlobalScalarExpression.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsGlobalScalarExpression : public UExposureExpressionsScalarValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsScalarExpressionName GlobalExpression;
    
    UExposureExpressionsGlobalScalarExpression();
};

