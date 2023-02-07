#pragma once
#include "CoreMinimal.h"
#include "LightCullingPerLightAdvancedSettings.h"
#include "LightCullingPerLightFeatureSettings.h"
#include "LightCullingPerLightSettings.generated.h"

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FLightCullingPerLightSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightCullingPerLightFeatureSettings LightingFeatures;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightCullingPerLightAdvancedSettings Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDisableDistanceCullingOverride: 1;
    
    FLightCullingPerLightSettings();
};

