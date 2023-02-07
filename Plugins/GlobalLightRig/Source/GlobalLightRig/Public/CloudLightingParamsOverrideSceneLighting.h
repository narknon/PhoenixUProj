#pragma once
#include "CoreMinimal.h"
#include "CloudLightingParams.h"
#include "VolumetricCloudsSceneLightRotatorParametersOverride.h"
#include "CloudLightingParamsOverrideSceneLighting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudLightingParamsOverrideSceneLighting : public UCloudLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSceneLightRotatorParametersOverride SceneLight;
    
    UCloudLightingParamsOverrideSceneLighting();
};

