#pragma once
#include "CoreMinimal.h"
#include "DampedSpringVector.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FDampedSpringVector {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DampingRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAcceleration;
    
public:
    FDampedSpringVector();
};

