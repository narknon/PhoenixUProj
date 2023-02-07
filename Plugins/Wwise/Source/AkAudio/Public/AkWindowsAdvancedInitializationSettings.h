#pragma once
#include "CoreMinimal.h"
#include "AkAdvancedInitializationSettingsWithMultiCoreRendering.h"
#include "AkWindowsAdvancedInitializationSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkWindowsAdvancedInitializationSettings : public FAkAdvancedInitializationSettingsWithMultiCoreRendering {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseHeadMountedDisplayAudioDevice;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 MaxSystemAudioObjects;
    
    AKAUDIO_API FAkWindowsAdvancedInitializationSettings();
};

