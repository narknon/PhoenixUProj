#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightAdvancedParameters.h"
#include "DirectionalLightBasicParameters.h"
#include "DirectionalLightCascadedShadowMaps.h"
#include "DirectionalLightDistanceFieldShadows.h"
#include "DirectionalLightShadows.h"
#include "DirectionalLightShafts.h"
#include "DirectionalLightParameters.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FDirectionalLightParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParameters Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightAdvancedParameters Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShafts LightShafts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShadows Shadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightDistanceFieldShadows DistanceFieldShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightCascadedShadowMaps CascadedShadowMaps;
    
    FDirectionalLightParameters();
};

