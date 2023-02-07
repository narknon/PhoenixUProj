#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtra.h"
#include "ExposureExpressionsExtraScalarName.h"
#include "ExposureExpressionsExtraScalarConstant.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraScalarConstant : public FExposureExpressionsExtra {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraScalarName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraScalarConstant();
};

