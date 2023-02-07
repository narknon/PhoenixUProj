#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsAdvancedParametersOverride.h"
#include "VolumetricCloudsBasicParametersOverride.h"
#include "VolumetricCloudsSceneLightParametersOverride.h"
#include "VolumetricCloudsShadowParametersOverride.h"
#include "VolumetricCloudsSkyLightParametersOverride.h"
#include "VolumetricCloudsLightingParametersOverride.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FVolumetricCloudsLightingParametersOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSkyLightParametersOverride SkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsShadowParametersOverride Shadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsAdvancedParametersOverride Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSceneLightParametersOverride SceneLight;
    
    FVolumetricCloudsLightingParametersOverride();
};

