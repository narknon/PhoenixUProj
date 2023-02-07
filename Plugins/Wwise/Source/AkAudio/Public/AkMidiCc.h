#pragma once
#include "CoreMinimal.h"
#include "AkMidiEventBase.h"
#include "EAkMidiCcValues.h"
#include "AkMidiCc.generated.h"

USTRUCT(BlueprintType)
struct FAkMidiCc : public FAkMidiEventBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkMidiCcValues Cc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Value;
    
    AKAUDIO_API FAkMidiCc();
};

