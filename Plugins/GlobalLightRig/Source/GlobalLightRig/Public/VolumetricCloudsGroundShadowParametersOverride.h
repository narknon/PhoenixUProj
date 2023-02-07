#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsGroundShadowParametersOverride.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FVolumetricCloudsGroundShadowParametersOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_ShadowStrength: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_CutOutDistanceMeters: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_CutOutFadeDistanceMeters: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShadowStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CutOutDistanceMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CutOutFadeDistanceMeters;
    
    FVolumetricCloudsGroundShadowParametersOverride();
};

