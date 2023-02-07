#pragma once
#include "CoreMinimal.h"
#include "LightComponentState.h"
#include "LightComponentStateBoolMap.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateBoolMap : public ULightComponentState {
    GENERATED_BODY()
public:
    ULightComponentStateBoolMap();
};

