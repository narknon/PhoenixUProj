#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereOzoneParametersOverride.h"
#include "SkyAtmosphereParams.h"
#include "SkyAtmosphereParamsOverrideOzone.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyAtmosphereParamsOverrideOzone : public USkyAtmosphereParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereOzoneParametersOverride Ozone;
    
    USkyAtmosphereParamsOverrideOzone();
};

