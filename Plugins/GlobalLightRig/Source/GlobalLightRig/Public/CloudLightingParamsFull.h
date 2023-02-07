#pragma once
#include "CoreMinimal.h"
#include "CloudLightingParams.h"
#include "VolumetricCloudsLightingParameters.h"
#include "CloudLightingParamsFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudLightingParamsFull : public UCloudLightingParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsLightingParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetSceneLighting;
    
    UCloudLightingParamsFull();
};

