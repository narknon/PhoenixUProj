#pragma once
#include "CoreMinimal.h"
#include "LookLimits.generated.h"

USTRUCT(BlueprintType)
struct FLookLimits {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Horizontal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Vertical;
    
    AVAANIMATION_API FLookLimits();
};

