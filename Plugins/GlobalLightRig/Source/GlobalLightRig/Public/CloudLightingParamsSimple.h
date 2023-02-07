#pragma once
#include "CoreMinimal.h"
#include "CloudLightingParams.h"
#include "VolumetricCloudsBasicParameters.h"
#include "VolumetricCloudsSkyLightParameters.h"
#include "CloudLightingParamsSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudLightingParamsSimple : public UCloudLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsBasicParameters Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsSkyLightParameters SkyLight;
    
    UCloudLightingParamsSimple();
};

