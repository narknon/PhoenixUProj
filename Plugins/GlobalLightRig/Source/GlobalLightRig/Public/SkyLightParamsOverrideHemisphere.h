#pragma once
#include "CoreMinimal.h"
#include "SkyLightHemisphereParametersOverride.h"
#include "SkyLightParams.h"
#include "SkyLightParamsOverrideHemisphere.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsOverrideHemisphere : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightHemisphereParametersOverride Hemisphere;
    
    USkyLightParamsOverrideHemisphere();
};

