#pragma once
#include "CoreMinimal.h"
#include "AkChannelConfiguration.h"
#include "PanningRule.h"
#include "AkOutputSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkOutputSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AudioDeviceSharesetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 IdDevice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    PanningRule PanRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AkChannelConfiguration ChannelConfig;
    
    AKAUDIO_API FAkOutputSettings();
};

