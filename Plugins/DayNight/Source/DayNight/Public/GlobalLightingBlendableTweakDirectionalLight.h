#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightBasicParametersOverride.h"
#include "DirectionalLightShadowsOverride.h"
#include "DirectionalLightShaftsOverride.h"
#include "EDayNightTweakDirectionalLightMode.h"
#include "GlobalLightingBlendableDayNightBase.h"
#include "GlobalLightingBlendableTweakDirectionalLight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UGlobalLightingBlendableTweakDirectionalLight : public UGlobalLightingBlendableDayNightBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightTweakDirectionalLightMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TweakAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TweakAzimuth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParametersOverride LightParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShaftsOverride LightShafts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShadowsOverride Shadows;
    
    UGlobalLightingBlendableTweakDirectionalLight();
};

