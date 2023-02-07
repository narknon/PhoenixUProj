#pragma once
#include "CoreMinimal.h"
#include "SkyLightAdvancedParametersOverride.h"
#include "SkyLightParams.h"
#include "SkyLightParamsOverrideAdvanced.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsOverrideAdvanced : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightAdvancedParametersOverride Advanced;
    
    USkyLightParamsOverrideAdvanced();
};

