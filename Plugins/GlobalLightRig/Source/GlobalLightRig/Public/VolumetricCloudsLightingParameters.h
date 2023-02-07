#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsAdvancedParameters.h"
#include "VolumetricCloudsBasicParameters.h"
#include "VolumetricCloudsSceneLightParameters.h"
#include "VolumetricCloudsShadowParameters.h"
#include "VolumetricCloudsSkyLightParameters.h"
#include "VolumetricCloudsLightingParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FVolumetricCloudsLightingParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsBasicParameters Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSkyLightParameters SkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsShadowParameters Shadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsAdvancedParameters Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSceneLightParameters SceneLight;
    
    FVolumetricCloudsLightingParameters();
};

