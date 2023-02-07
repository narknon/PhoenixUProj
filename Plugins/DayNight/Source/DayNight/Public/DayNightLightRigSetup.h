#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightBasicParameters.h"
#include "DirectionalLightShafts.h"
#include "ProbeContactShadowsParameters.h"
#include "ProbeLightingAdjustmentParameters.h"
#include "ProbeLightingToneMapParameters.h"
#include "SkyAtmosphereParameters.h"
#include "SkyLightBasicParameters.h"
#include "SkyLightHemisphereParameters.h"
#include "VolumetricCloudsAdvancedParameters.h"
#include "VolumetricCloudsBasicParameters.h"
#include "VolumetricCloudsSceneLightParameters.h"
#include "VolumetricCloudsShadowParameters.h"
#include "VolumetricCloudsSkyLightParameters.h"
#include "DayNightCloudSceneLighting.h"
#include "DayNightLightRigSetup.generated.h"

USTRUCT(BlueprintType)
struct FDayNightLightRigSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParameters DirectionalLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShafts DirectionalLightShafts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightBasicParameters SkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightHemisphereParameters SkyLightHemisphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereParameters SkyAtmosphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsBasicParameters CloudLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsAdvancedParameters CloudsAdvanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsShadowParameters CloudsShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSkyLightParameters CloudsSkyLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightCloudSceneLighting CloudSceneLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSceneLightParameters CloudsSceneLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingAdjustmentParameters ProbeLightingAdjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeLightingToneMapParameters ProbeLightingToneMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProbeContactShadowsParameters ProbeContactShadows;
    
    DAYNIGHT_API FDayNightLightRigSetup();
};

