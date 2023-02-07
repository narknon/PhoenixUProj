#pragma once
#include "CoreMinimal.h"
#include "LightSettingsModCurve.h"
#include "LightSettingsModColorBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModColorBase : public ULightSettingsModCurve {
    GENERATED_BODY()
public:
    ULightSettingsModColorBase();
};

