#pragma once
#include "CoreMinimal.h"
#include "ESkinFXDelegateEvent.generated.h"

UENUM(BlueprintType)
enum class ESkinFXDelegateEvent : uint8 {
    Event_Start,
    Event_Restart,
    Event_Finish,
    Envelope_StartAttack,
    Envelope_FirstEnterSustain,
    Envelope_LoopSustain,
    Envelope_BeginRelease,
    Envelope_EndRelease,
    EndCalled_Immediately,
    EndCalled_JumpToRelease,
    EndCalled_EndSustainHold,
};

