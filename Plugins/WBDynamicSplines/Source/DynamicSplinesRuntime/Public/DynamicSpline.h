#pragma once
#include "CoreMinimal.h"
#include "ControlPoint.h"
#include "ESplineInterpMode.h"
#include "NamedBoneInfluences.h"
#include "DynamicSpline.generated.h"

USTRUCT(BlueprintType)
struct FDynamicSpline {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FControlPoint> ControlPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FNamedBoneInfluences> ControlPointInfluences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<float> Keys;
    
    UPROPERTY(EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<ESplineInterpMode> InterpModes;
    
    DYNAMICSPLINESRUNTIME_API FDynamicSpline();
};

