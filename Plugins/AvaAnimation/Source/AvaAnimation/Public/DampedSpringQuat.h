#pragma once
#include "CoreMinimal.h"
#include "DampedSpringQuat.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDampedSpringQuat {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DampingRatio;
    
public:
    FDampedSpringQuat();
};

