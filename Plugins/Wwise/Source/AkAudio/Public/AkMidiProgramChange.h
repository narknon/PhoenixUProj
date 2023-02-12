#pragma once
#include "CoreMinimal.h"
#include "AkMidiEventBase.h"
#include "AkMidiProgramChange.generated.h"

USTRUCT(BlueprintType)
struct FAkMidiProgramChange : public FAkMidiEventBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ProgramNum;
    
    AKAUDIO_API FAkMidiProgramChange();
};

