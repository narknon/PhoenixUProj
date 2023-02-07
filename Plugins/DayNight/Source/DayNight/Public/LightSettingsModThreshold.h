#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LightSettingsModThreshold.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API ULightSettingsModThreshold : public UObject {
    GENERATED_BODY()
public:
    ULightSettingsModThreshold();
};

