#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightingBlendableInputType.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableExpHeightFog.generated.h"

class UExpHeightFogParams;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableExpHeightFog : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExpHeightFogParams* ExpHeightFogParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightingBlendableInputType OverrideSource;
    
    UGlobalLightingBlendableExpHeightFog();
};

