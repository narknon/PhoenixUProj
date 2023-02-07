#pragma once
#include "CoreMinimal.h"
#include "DampedSpringRotator.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDampedSpringRotator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DampingRatio;
    
public:
    FDampedSpringRotator();
};

