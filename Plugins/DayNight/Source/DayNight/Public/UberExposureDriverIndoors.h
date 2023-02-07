#pragma once
#include "CoreMinimal.h"
#include "UberExposureDriver.h"
#include "UberExposureDriverIndoors.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UUberExposureDriverIndoors : public UUberExposureDriver {
    GENERATED_BODY()
public:
    UUberExposureDriverIndoors();
};

