#pragma once
#include "CoreMinimal.h"
#include "UberExposureComponentSunAltitude.h"
#include "UberExposureComponentSunAltitudeReference.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UUberExposureComponentSunAltitudeReference : public UUberExposureComponentSunAltitude {
    GENERATED_BODY()
public:
    UUberExposureComponentSunAltitudeReference();
};

