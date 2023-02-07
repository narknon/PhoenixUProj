#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableDirectionalLightsOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableDirectionalLightsOff : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceVisibilityOff;
    
    UGlobalLightingBlendableDirectionalLightsOff();
};

