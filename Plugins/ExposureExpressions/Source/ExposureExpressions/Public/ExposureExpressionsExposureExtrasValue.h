#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsExtraExposureName.h"
#include "ExposureExpressionsExposureExtrasValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureExtrasValue : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraExposureName Value;
    
    UExposureExpressionsExposureExtrasValue();
};

