#pragma once
#include "CoreMinimal.h"
#include "AkGeometrySurfaceOverride.generated.h"

class UAkAcousticTexture;

USTRUCT(BlueprintType)
struct FAkGeometrySurfaceOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAcousticTexture* AcousticTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEnableOcclusionOverride: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OcclusionValue;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SurfaceArea;
    
public:
    AKAUDIO_API FAkGeometrySurfaceOverride();
};

