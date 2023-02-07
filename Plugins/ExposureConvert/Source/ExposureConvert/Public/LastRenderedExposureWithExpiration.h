#pragma once
#include "CoreMinimal.h"
#include "LastRenderedExposure.h"
#include "LastRenderedExposureWithExpiration.generated.h"

USTRUCT(BlueprintType)
struct EXPOSURECONVERT_API FLastRenderedExposureWithExpiration : public FLastRenderedExposure {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 MaxAge;
    
    FLastRenderedExposureWithExpiration();
};

