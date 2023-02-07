#pragma once
#include "CoreMinimal.h"
#include "SkeletonCurveReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSkeletonCurveReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurveName;
    
    FSkeletonCurveReference();
};

