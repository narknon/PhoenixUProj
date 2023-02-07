#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtra.h"
#include "ExposureExpressionsExtraExposureName.h"
#include "ExposureExpressionsExtraExposure.generated.h"

class UExposureExpressionsExposureValue;

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraExposure : public FExposureExpressionsExtra {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraExposureName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* Expression;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraExposure();
};

