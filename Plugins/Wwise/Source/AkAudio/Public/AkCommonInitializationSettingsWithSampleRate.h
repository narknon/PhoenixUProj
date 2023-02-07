#pragma once
#include "CoreMinimal.h"
#include "AkCommonInitializationSettings.h"
#include "AkCommonInitializationSettingsWithSampleRate.generated.h"

USTRUCT(BlueprintType)
struct FAkCommonInitializationSettingsWithSampleRate : public FAkCommonInitializationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 SampleRate;
    
    AKAUDIO_API FAkCommonInitializationSettingsWithSampleRate();
};

