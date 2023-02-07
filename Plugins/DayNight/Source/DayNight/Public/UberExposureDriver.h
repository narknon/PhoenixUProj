#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarsDriver.h"
#include "UberExposureDriver.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UUberExposureDriver : public UPostProcessingVarsDriver {
    GENERATED_BODY()
public:
    UUberExposureDriver();
};

