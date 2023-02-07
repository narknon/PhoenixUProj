#pragma once
#include "CoreMinimal.h"
#include "UberExposureComponent.h"
#include "UberExposureComponentConstDriver.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UUberExposureComponentConstDriver : public UUberExposureComponent {
    GENERATED_BODY()
public:
    UUberExposureComponentConstDriver();
};

