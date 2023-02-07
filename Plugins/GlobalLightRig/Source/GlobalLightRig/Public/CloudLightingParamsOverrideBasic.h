#pragma once
#include "CoreMinimal.h"
#include "CloudLightingParams.h"
#include "VolumetricCloudsBasicParametersOverride.h"
#include "VolumetricCloudsSkyLightParametersOverride.h"
#include "CloudLightingParamsOverrideBasic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudLightingParamsOverrideBasic : public UCloudLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSkyLightParametersOverride SkyLight;
    
    UCloudLightingParamsOverrideBasic();
};

