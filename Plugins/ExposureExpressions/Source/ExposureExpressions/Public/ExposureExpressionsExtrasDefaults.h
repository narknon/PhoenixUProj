#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraDefaultExposure.h"
#include "ExposureExpressionsExtraDefaultExposureConstant.h"
#include "ExposureExpressionsExtraDefaultScalar.h"
#include "ExposureExpressionsExtraDefaultScalarConstant.h"
#include "ExposureExpressionsExtrasDefaults.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressionsExtrasDefaults {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraDefaultExposureConstant> ExposureConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraDefaultExposure> ExposureExtras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraDefaultScalarConstant> ScalarConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraDefaultScalar> ScalarExtras;
    
    FExposureExpressionsExtrasDefaults();
};

