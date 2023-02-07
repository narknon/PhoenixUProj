#pragma once
#include "CoreMinimal.h"
#include "EAvaAudioDialogueEmotionHint.generated.h"

UENUM(BlueprintType)
enum class EAvaAudioDialogueEmotionHint : uint8 {
    DEH_None,
    DEH_Alarm,
    DEH_Amusement,
    DEH_Angry,
    DEH_Anguish,
    DEH_Annoyance,
    DEH_Anticipation,
    DEH_Anxiety,
    DEH_Confused,
    DEH_Dead,
    DEH_Delight,
    DEH_Disgust,
    DEH_Fear,
    DEH_Happy,
    DEH_Impressed,
    DEH_Neutral,
    DEH_Pacify,
    DEH_Sad,
    DEH_Sick,
    DEH_Sleep,
    DEH_Surprise,
    DEH_Trust,
    DEH_Valor,
    DEH_MAX UMETA(Hidden),
};

