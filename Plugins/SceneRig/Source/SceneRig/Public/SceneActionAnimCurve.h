#pragma once
#include "CoreMinimal.h"
#include "SkeletonCurveReference.h"
#include "SceneActionAnimCurve.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct FSceneActionAnimCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkeletonCurveReference CurveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Value;
    
    SCENERIG_API FSceneActionAnimCurve();
};

