#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtra.h"
#include "ExposureExpressionsExtraExposureName.h"
#include "ExposureExpressionsExtraExposureConstant.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraExposureConstant : public FExposureExpressionsExtra {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraExposureName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraExposureConstant();
};

