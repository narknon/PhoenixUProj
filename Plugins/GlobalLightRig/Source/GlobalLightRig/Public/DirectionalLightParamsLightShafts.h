#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightShafts.h"
#include "DirectionalLightParamsLightShafts.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsLightShafts : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShafts LightShafts;
    
    UDirectionalLightParamsLightShafts();
};

