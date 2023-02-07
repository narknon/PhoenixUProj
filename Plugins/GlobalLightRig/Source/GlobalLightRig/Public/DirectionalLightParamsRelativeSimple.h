#pragma once
#include "CoreMinimal.h"
#include "DirectionalLightBasicParametersRelative.h"
#include "DirectionalLightParams.h"
#include "DirectionalLightShaftsRelative.h"
#include "DirectionalLightParamsRelativeSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UDirectionalLightParamsRelativeSimple : public UDirectionalLightParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightBasicParametersRelative Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDirectionalLightShaftsRelative LightShafts;
    
    UDirectionalLightParamsRelativeSimple();
};

