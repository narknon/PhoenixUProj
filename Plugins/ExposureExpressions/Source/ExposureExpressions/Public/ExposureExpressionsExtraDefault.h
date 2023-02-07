#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraDefault.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraDefault {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Targets;
    
    FExposureExpressionsExtraDefault();
};

