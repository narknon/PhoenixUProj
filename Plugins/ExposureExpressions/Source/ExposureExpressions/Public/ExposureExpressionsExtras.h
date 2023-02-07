#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraExposure.h"
#include "ExposureExpressionsExtraExposureConstant.h"
#include "ExposureExpressionsExtraScalar.h"
#include "ExposureExpressionsExtraScalarConstant.h"
#include "ExposureExpressionsExtras.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressionsExtras {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraExposureConstant> ExposureConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraExposure> ExposureExtras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraScalarConstant> ScalarConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraScalar> ScalarExtras;
    
    FExposureExpressionsExtras();
};

