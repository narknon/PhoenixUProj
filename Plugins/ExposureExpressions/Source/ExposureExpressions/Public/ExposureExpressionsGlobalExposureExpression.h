#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureExpressionName.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsGlobalExposureExpression.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsGlobalExposureExpression : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExposureExpressionName GlobalExpression;
    
    UExposureExpressionsGlobalExposureExpression();
};

