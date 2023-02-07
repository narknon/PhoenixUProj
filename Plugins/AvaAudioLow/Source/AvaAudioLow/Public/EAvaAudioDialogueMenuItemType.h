#pragma once
#include "CoreMinimal.h"
#include "EAvaAudioDialogueMenuItemType.generated.h"

UENUM(BlueprintType)
enum class EAvaAudioDialogueMenuItemType : uint8 {
    MIT_None,
    MIT_Info,
    MIT_InfoHub,
    MIT_StraightPath,
    MIT_Special,
    MIT_BackTo,
    MIT_Exit,
    MIT_MainMission,
    MIT_SideMission,
    MIT_Assignment,
    MIT_Conversation,
    MIT_Vendor,
    MIT_MAX UMETA(Hidden),
};

