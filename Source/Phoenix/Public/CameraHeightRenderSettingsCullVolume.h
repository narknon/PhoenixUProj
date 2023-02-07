#pragma once
#include "CoreMinimal.h"
#include "CameraHeightRenderSettingsCullVolume.generated.h"

class ACullDistanceVolume;

USTRUCT(BlueprintType)
struct FCameraHeightRenderSettingsCullVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACullDistanceVolume* CullDistanceVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ApplyAtBlendPercent;
    
    PHOENIX_API FCameraHeightRenderSettingsCullVolume();
};

