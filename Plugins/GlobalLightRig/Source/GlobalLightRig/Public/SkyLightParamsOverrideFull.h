#pragma once
#include "CoreMinimal.h"
#include "SkyLightLightingParametersOverride.h"
#include "SkyLightParams.h"
#include "SkyLightParamsOverrideFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsOverrideFull : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightLightingParametersOverride Parameters;
    
    USkyLightParamsOverrideFull();
};

