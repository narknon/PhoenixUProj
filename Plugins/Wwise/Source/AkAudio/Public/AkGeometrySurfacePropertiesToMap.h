#pragma once
#include "CoreMinimal.h"
#include "AkGeometrySurfacePropertiesToMap.generated.h"

class UAkAcousticTexture;

USTRUCT(BlueprintType)
struct FAkGeometrySurfacePropertiesToMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAkAcousticTexture> AcousticTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OcclusionValue;
    
    AKAUDIO_API FAkGeometrySurfacePropertiesToMap();
};

