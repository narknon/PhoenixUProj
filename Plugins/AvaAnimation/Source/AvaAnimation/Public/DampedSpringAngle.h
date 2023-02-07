#pragma once
#include "CoreMinimal.h"
#include "DampedSpringAngle.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDampedSpringAngle {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DampingRatio;
    
public:
    FDampedSpringAngle();
};

