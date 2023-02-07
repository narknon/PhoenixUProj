#pragma once
#include "CoreMinimal.h"
#include "LightComponentState.h"
#include "LightComponentStateFloatMap.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateFloatMap : public ULightComponentState {
    GENERATED_BODY()
public:
    ULightComponentStateFloatMap();
};

