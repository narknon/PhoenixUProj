#pragma once
#include "CoreMinimal.h"
#include "Curves/RealCurve.h"
#include "Curves/RichCurve.h"
#include "MovieSceneTangentDataSerializationHelper.h"
#include "MovieSceneFloatValueSerializationHelper.generated.h"

USTRUCT(BlueprintType)
struct FMovieSceneFloatValueSerializationHelper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERichCurveInterpMode> InterpMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERichCurveTangentMode> TangentMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneTangentDataSerializationHelper Tangent;
    
    AKAUDIO_API FMovieSceneFloatValueSerializationHelper();
};

