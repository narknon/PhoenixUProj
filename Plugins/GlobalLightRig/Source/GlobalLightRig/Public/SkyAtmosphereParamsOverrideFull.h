#pragma once
#include "CoreMinimal.h"
#include "SkyAtmosphereParametersOverride.h"
#include "SkyAtmosphereParams.h"
#include "SkyAtmosphereParamsOverrideFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyAtmosphereParamsOverrideFull : public USkyAtmosphereParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyAtmosphereParametersOverride Parameters;
    
    USkyAtmosphereParamsOverrideFull();
};

