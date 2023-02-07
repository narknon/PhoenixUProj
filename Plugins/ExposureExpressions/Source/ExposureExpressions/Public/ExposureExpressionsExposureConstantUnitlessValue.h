#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureConstant.h"
#include "ExposureExpressionsExposureConstantUnitlessValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureConstantUnitlessValue : public UExposureExpressionsExposureConstant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UExposureExpressionsExposureConstantUnitlessValue();
};

