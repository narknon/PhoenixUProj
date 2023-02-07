#pragma once
#include "CoreMinimal.h"
#include "Curves/RealCurve.h"
#include "MovieSceneFloatValueSerializationHelper.h"
#include "MovieSceneFloatChannelSerializationHelper.generated.h"

USTRUCT(BlueprintType)
struct FMovieSceneFloatChannelSerializationHelper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERichCurveExtrapolation> PreInfinityExtrap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERichCurveExtrapolation> PostInfinityExtrap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> Times;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovieSceneFloatValueSerializationHelper> Values;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasDefaultValue;
    
    AKAUDIO_API FMovieSceneFloatChannelSerializationHelper();
};

