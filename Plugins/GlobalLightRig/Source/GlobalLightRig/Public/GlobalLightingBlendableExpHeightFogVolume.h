#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendable.h"
#include "GlobalLightingBlendableExpHeightFogVolume.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, HideDropdown)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableExpHeightFogVolume : public UGlobalLightingBlendable {
    GENERATED_BODY()
public:
    UGlobalLightingBlendableExpHeightFogVolume();
};

