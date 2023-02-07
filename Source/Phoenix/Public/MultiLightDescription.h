#pragma once
#include "CoreMinimal.h"
#include "BasicLightDescription.h"
#include "EBasicLightType.h"
#include "PointLightDescription.h"
#include "RectLightDescription.h"
#include "SpotLightDescription.h"
#include "MultiLightDescription.generated.h"

USTRUCT(BlueprintType)
struct FMultiLightDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBasicLightType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBasicLightDescription Common;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPointLightDescription Point;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpotLightDescription Spot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRectLightDescription Rect;
    
    PHOENIX_API FMultiLightDescription();
};

