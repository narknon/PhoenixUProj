#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateTag.h"
#include "LightComponentStateRemoveTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateRemoveTag : public ULightComponentStateTag {
    GENERATED_BODY()
public:
    ULightComponentStateRemoveTag();
};

