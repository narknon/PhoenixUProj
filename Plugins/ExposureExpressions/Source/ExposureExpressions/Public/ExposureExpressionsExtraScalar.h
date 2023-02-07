#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtra.h"
#include "ExposureExpressionsExtraScalarName.h"
#include "ExposureExpressionsExtraScalar.generated.h"

class UExposureExpressionsScalarValue;

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraScalar : public FExposureExpressionsExtra {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraScalarName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsScalarValue* Expression;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraScalar();
};

