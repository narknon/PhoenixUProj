#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureConstant.h"
#include "ExposureExpressionsExposureConstantEV100Value.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureConstantEV100Value : public UExposureExpressionsExposureConstant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UExposureExpressionsExposureConstantEV100Value();
};

