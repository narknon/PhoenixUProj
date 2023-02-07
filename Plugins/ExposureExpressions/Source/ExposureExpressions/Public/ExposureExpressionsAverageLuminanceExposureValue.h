#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsAverageLuminanceExposureValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsAverageLuminanceExposureValue : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSmoothed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbiased;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseHistory;
    
    UExposureExpressionsAverageLuminanceExposureValue();
};

