#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EWInstrumentedProfilerAutomatedResumeSettings.h"
#include "WInstrumentedProfilerCategoryAvailability.h"
#include "WExternalProfilersSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig)
class WINSTRUMENTEDPROFILERSSETTINGS_API UWExternalProfilersSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWInstrumentedProfilerAutomatedResumeSettings AutomatedResume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWInstrumentedProfilerCategoryAvailability> Categories;
    
    UWExternalProfilersSettings();
};

