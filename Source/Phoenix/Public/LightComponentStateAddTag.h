#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateTag.h"
#include "LightComponentStateAddTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateAddTag : public ULightComponentStateTag {
    GENERATED_BODY()
public:
    ULightComponentStateAddTag();
};

