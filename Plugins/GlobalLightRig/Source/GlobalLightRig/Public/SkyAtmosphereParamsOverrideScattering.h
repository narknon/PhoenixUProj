#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereParams.h"
#include "SkyAtmosphereScatteringParametersOverride.h"
#include "SkyAtmosphereParamsOverrideScattering.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyAtmosphereParamsOverrideScattering : public USkyAtmosphereParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereScatteringParametersOverride Scattering;
    
    USkyAtmosphereParamsOverrideScattering();
};

