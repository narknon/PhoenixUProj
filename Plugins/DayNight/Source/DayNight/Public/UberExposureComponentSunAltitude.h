#pragma once
#include "CoreMinimal.h"
#include "UberExposureComponentConstDriver.h"
#include "UberExposureComponentSunAltitude.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UUberExposureComponentSunAltitude : public UUberExposureComponentConstDriver {
    GENERATED_BODY()
public:
    UUberExposureComponentSunAltitude();
};

