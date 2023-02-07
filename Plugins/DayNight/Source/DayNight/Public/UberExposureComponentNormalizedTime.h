#pragma once
#include "CoreMinimal.h"
#include "UberExposureComponentConstDriver.h"
#include "UberExposureComponentNormalizedTime.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UUberExposureComponentNormalizedTime : public UUberExposureComponentConstDriver {
    GENERATED_BODY()
public:
    UUberExposureComponentNormalizedTime();
};

