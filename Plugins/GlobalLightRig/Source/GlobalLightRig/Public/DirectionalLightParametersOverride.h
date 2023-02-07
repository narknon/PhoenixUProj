#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightAdvancedParametersOverride.h"
#include "DirectionalLightBasicParametersOverride.h"
#include "DirectionalLightCascadedShadowMapsOverride.h"
#include "DirectionalLightDistanceFieldShadowsOverride.h"
#include "DirectionalLightShadowsOverride.h"
#include "DirectionalLightShaftsOverride.h"
#include "DirectionalLightParametersOverride.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FDirectionalLightParametersOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightAdvancedParametersOverride Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShaftsOverride LightShafts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShadowsOverride Shadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightDistanceFieldShadowsOverride DistanceFieldShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightCascadedShadowMapsOverride CascadedShadowMaps;
    
    FDirectionalLightParametersOverride();
};

