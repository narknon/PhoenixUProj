#pragma once
#include "CoreMinimal.h"
#include "AkAdvancedInitializationSettingsWithMultiCoreRendering.h"
#include "AkXboxOneGDKAdvancedInitializationSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkXboxOneGDKAdvancedInitializationSettings : public FAkAdvancedInitializationSettingsWithMultiCoreRendering {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 MaximumNumberOfXMAVoices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseHardwareCodecLowLatencyMode;
    
    AKAUDIO_API FAkXboxOneGDKAdvancedInitializationSettings();
};

