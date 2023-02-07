#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateData.h"
#include "LightComponentStateDataFloatMap.generated.h"

UCLASS(Blueprintable, NonTransient)
class ULightComponentStateDataFloatMap : public ULightComponentStateData {
    GENERATED_BODY()
public:
    ULightComponentStateDataFloatMap();
};

