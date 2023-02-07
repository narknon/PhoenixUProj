#pragma once
#include "CoreMinimal.h"
#include "AvaAudioDialogueFlags.generated.h"

UENUM(BlueprintType)
enum class AvaAudioDialogueFlags : uint8 {
    DLGFLAG_None,
    DLGFLAG_FromConversation,
    DLGFLAG_StartPaused,
    DLGFLAG_DontDispatchLipsyncMessage = 0x4,
    DLGFLAG_NoQueuingLimits = 0x8,
    DLGFLAG_SuppressSubtitles = 0x10,
    DLGFLAG_NonSpatialized = 0x20,
    DLGFLAG_UseCinematicPolyphony = 0x40,
    DLGFLAG_MouthLipsyncOnly = 0x80,
    DLGFLAG_MAX UMETA(Hidden),
};

