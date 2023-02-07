#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EWInstrumentedProfilerAutomatedResumeSettings.h"
#include "WInstrumentedProfilerCategoryAvailability.h"
#include "WTelemetrySettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig)
class WINSTRUMENTEDPROFILERSSETTINGS_API UWTelemetrySettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWInstrumentedProfilerAutomatedResumeSettings AutomatedResume;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableTelemetry;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TelemetrySizeInKB;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ConnectionAddress;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWInstrumentedProfilerCategoryAvailability> Categories;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBreakOnMismatchedZone;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TelemetryMaxThreadCount;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TelemetryMaxTimeSpanTrackCount;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableContextSwitches;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableMessages;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableOutputDebugInfo;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBreakOnWarning;
    
    UWTelemetrySettings();
};

