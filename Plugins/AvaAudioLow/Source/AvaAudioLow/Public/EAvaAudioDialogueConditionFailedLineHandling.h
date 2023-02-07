#pragma once
#include "CoreMinimal.h"
#include "EAvaAudioDialogueConditionFailedLineHandling.generated.h"

UENUM(BlueprintType)
enum class EAvaAudioDialogueConditionFailedLineHandling : uint8 {
    CFH_Suppress_Display,
    CFH_Show_Disabled_Unknown_Reason,
    CFH_Show_Disabled_Not_Enough_Money,
    CFH_Show_Disabled_Social_Capital_Too_Low,
    CFH_Show_Disabled_Faction_Capital_Too_Low,
    CFH_Show_Disabled_Knowledge_Too_Low,
    CFH_Show_Disabled_Curriculum_Level_Too_Low,
    CFH_Show_Disabled_Missing_Inventory,
    CFH_Show_Disabled_Not_Equipped,
    CFH_Show_Disabled_SanctElf_Task_Cooldown,
    CFH_MAX UMETA(Hidden),
};

