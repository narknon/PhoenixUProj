#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PostProcessingVarsDriver.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class RENDERSETTINGS_API UPostProcessingVarsDriver : public UObject {
    GENERATED_BODY()
public:
    UPostProcessingVarsDriver();
};

