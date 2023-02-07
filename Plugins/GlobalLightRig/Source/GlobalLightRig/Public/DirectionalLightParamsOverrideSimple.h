#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightBasicParametersOverride.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightShaftsOverride.h"
#include "DirectionalLightParamsOverrideSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsOverrideSimple : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShaftsOverride LightShafts;
    
    UDirectionalLightParamsOverrideSimple();
};

