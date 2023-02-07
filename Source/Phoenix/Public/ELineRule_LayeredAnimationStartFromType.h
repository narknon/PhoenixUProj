#pragma once
#include "CoreMinimal.h"
#include "ELineRule_LayeredAnimationStartFromType.generated.h"

UENUM(BlueprintType)
enum class ELineRule_LayeredAnimationStartFromType : uint8 {
    DialogueLineStart,
    LipsyncPause,
    LipsyncMe,
    LipsyncYou,
    LipsyncQuickly,
    LipsyncAffirmative,
    LipsyncNegative,
    LipsyncHere,
    LipsyncThere,
    LipsyncSuperlative,
    LipsyncGreet,
    LipsyncLaugh,
    LipsyncThink,
    ToneChanges,
    ToneLowToHigh,
    ToneHighToLow,
    ELineRule_MAX UMETA(Hidden),
};

