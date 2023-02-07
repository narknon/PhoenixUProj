#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsDropdownName.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsDropdownName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    EXPOSUREEXPRESSIONS_API FExposureExpressionsDropdownName();
};

