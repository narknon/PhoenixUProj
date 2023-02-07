#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DynamicLightAdaptationModSettingsInterface.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsInterface : public UObject {
    GENERATED_BODY()
public:
    UDynamicLightAdaptationModSettingsInterface();
};

