#pragma once
#include "CoreMinimal.h"
#include "LightComponentState.h"
#include "LightComponentStateIntMap.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateIntMap : public ULightComponentState {
    GENERATED_BODY()
public:
    ULightComponentStateIntMap();
};

