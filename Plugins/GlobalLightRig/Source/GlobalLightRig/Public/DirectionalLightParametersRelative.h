#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightAdvancedParametersRelative.h"
#include "DirectionalLightBasicParametersRelative.h"
#include "DirectionalLightCascadedShadowMapsRelative.h"
#include "DirectionalLightDistanceFieldShadowsRelative.h"
#include "DirectionalLightShadowsRelative.h"
#include "DirectionalLightShaftsRelative.h"
#include "DirectionalLightParametersRelative.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FDirectionalLightParametersRelative {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParametersRelative Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightAdvancedParametersRelative Advanced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShaftsRelative LightShafts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShadowsRelative Shadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightDistanceFieldShadowsRelative DistanceFieldShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightCascadedShadowMapsRelative CascadedShadowMaps;
    
    FDirectionalLightParametersRelative();
};

