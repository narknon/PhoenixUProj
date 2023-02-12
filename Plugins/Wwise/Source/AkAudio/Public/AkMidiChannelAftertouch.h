#pragma once
#include "CoreMinimal.h"
#include "AkMidiEventBase.h"
#include "AkMidiChannelAftertouch.generated.h"

USTRUCT(BlueprintType)
struct FAkMidiChannelAftertouch : public FAkMidiEventBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Value;
    
    AKAUDIO_API FAkMidiChannelAftertouch();
};

