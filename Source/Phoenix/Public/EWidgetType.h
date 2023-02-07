#pragma once
#include "CoreMinimal.h"
#include "EWidgetType.generated.h"

UENUM(BlueprintType)
enum class EWidgetType : uint8 {
    WT_Social,
    WT_Enemy,
    WT_Creature,
    WT_Blip,
    WT_Interact,
    WT_Climb,
    WT_SocialBlip,
    WT_None,
    WT_MAX UMETA(Hidden),
};

