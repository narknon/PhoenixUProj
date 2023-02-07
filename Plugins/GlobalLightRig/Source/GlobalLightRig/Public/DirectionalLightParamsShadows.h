#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightShadows.h"
#include "DirectionalLightParamsShadows.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsShadows : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShadows Shadows;
    
    UDirectionalLightParamsShadows();
};

