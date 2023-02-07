#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightParametersOverride.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightParamsOverrideFull.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsOverrideFull : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightParametersOverride Parameters;
    
    UDirectionalLightParamsOverrideFull();
};

