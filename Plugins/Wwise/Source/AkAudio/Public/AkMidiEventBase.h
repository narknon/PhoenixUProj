#pragma once
#include "CoreMinimal.h"
#include "EAkMidiEventType.h"
#include "AkMidiEventBase.generated.h"

USTRUCT(BlueprintType)
struct FAkMidiEventBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkMidiEventType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Chan;
    
    AKAUDIO_API FAkMidiEventBase();
};

