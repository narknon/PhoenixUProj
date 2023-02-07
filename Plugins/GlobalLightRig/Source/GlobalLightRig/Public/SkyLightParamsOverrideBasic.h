#pragma once
#include "CoreMinimal.h"
#include "SkyLightBasicParametersOverride.h"
#include "SkyLightParams.h"
#include "SkyLightParamsOverrideBasic.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API USkyLightParamsOverrideBasic : public USkyLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyLightBasicParametersOverride Basic;
    
    USkyLightParamsOverrideBasic();
};

