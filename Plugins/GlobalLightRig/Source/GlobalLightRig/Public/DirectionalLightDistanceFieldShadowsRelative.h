#pragma once
#include "CoreMinimal.h"
#include "AdjustedValueBoolean.h"
#include "AdjustedValueFloat.h"
#include "DirectionalLightDistanceFieldShadowsRelative.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FDirectionalLightDistanceFieldShadowsRelative {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueBoolean bUseRayTracedDistanceFieldShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat RayStartOffsetDepthScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat DistanceFieldShadowDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat TraceDistance;
    
    FDirectionalLightDistanceFieldShadowsRelative();
};

