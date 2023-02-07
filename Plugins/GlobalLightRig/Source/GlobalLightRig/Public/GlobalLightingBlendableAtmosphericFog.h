#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableAtmosphericFog.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableAtmosphericFog : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UGlobalLightingBlendableAtmosphericFog();
};

