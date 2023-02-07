#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightBasicParametersOverride.h"
#include "DirectionalLightShaftsOverride.h"
#include "ProbeContactShadowsParametersOverride.h"
#include "ProbeLightingAdjustmentParametersOverride.h"
#include "ProbeLightingToneMapParametersOverride.h"
#include "SkyAtmosphereParametersOverride.h"
#include "SkyLightBasicParametersOverride.h"
#include "SkyLightHemisphereParametersOverride.h"
#include "VolumetricCloudsAdvancedParametersOverride.h"
#include "VolumetricCloudsBasicParametersOverride.h"
#include "VolumetricCloudsShadowParametersOverride.h"
#include "VolumetricCloudsSkyLightParametersOverride.h"
#include "DayNightCloudSceneLightingOverride.h"
#include "DayNightLightRigOverride.generated.h"

USTRUCT(BlueprintType)
struct FDayNightLightRigOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParametersOverride DirectionalLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShaftsOverride DirectionalLightShafts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightBasicParametersOverride SkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightHemisphereParametersOverride SkyLightHemisphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereParametersOverride SkyAtmosphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsBasicParametersOverride CloudLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsAdvancedParametersOverride CloudsAdvanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsShadowParametersOverride CloudsShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSkyLightParametersOverride CloudsSkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightCloudSceneLightingOverride CloudSceneLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingAdjustmentParametersOverride ProbeLightingAdjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingToneMapParametersOverride ProbeLightingToneMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeContactShadowsParametersOverride ProbeContactShadows;
    
    DAYNIGHT_API FDayNightLightRigOverride();
};

