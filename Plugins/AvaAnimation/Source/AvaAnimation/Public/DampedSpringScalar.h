#pragma once
#include "CoreMinimal.h"
#include "DampedSpringScalar.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDampedSpringScalar {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DampingRatio;
    
public:
    FDampedSpringScalar();
};

