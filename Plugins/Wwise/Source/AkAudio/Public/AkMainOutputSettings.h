#pragma once
#include "CoreMinimal.h"
#include "EAkChannelConfigType.h"
#include "EAkPanningRule.h"
#include "AkMainOutputSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkMainOutputSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AudioDeviceShareset;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 DeviceID;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkPanningRule PanningRule;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkChannelConfigType ChannelConfigType;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ChannelMask;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NumberOfChannels;
    
    AKAUDIO_API FAkMainOutputSettings();
};

