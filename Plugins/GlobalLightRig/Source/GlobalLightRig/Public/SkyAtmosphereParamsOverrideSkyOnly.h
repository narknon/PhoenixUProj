#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereParams.h"
#include "SkyAtmosphereSkyOnlyParametersOverride.h"
#include "SkyAtmosphereParamsOverrideSkyOnly.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyAtmosphereParamsOverrideSkyOnly : public USkyAtmosphereParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereSkyOnlyParametersOverride SkyOnly;
    
    USkyAtmosphereParamsOverrideSkyOnly();
};

