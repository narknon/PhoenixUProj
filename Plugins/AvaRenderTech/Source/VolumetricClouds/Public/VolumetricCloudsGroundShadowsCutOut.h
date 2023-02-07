#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsGroundShadowsCutOut.generated.h"

USTRUCT(BlueprintType)
struct FVolumetricCloudsGroundShadowsCutOut {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeDistanceMeters;
    
    VOLUMETRICCLOUDS_API FVolumetricCloudsGroundShadowsCutOut();
};

