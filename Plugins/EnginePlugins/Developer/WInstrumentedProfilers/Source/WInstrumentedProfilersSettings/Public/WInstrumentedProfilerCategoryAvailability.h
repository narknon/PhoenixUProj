#pragma once
#include "CoreMinimal.h"
#include "EWInstrumentedProfilerAvailabilitySettings.h"
#include "EWInstrumentedProfilerCategorySettings.h"
#include "WInstrumentedProfilerCategoryAvailability.generated.h"

USTRUCT(BlueprintType)
struct FWInstrumentedProfilerCategoryAvailability {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EWInstrumentedProfilerCategorySettings Category;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EWInstrumentedProfilerAvailabilitySettings Availability;
    
    WINSTRUMENTEDPROFILERSSETTINGS_API FWInstrumentedProfilerCategoryAvailability();
};

