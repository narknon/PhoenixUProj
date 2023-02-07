#pragma once
#include "CoreMinimal.h"
#include "CloudLightingParams.h"
#include "VolumetricCloudsSceneLightRotatorParameters.h"
#include "CloudLightingParamsSceneLighting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudLightingParamsSceneLighting : public UCloudLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSceneLightRotatorParameters SceneLight;
    
    UCloudLightingParamsSceneLighting();
};

