#pragma once
#include "CoreMinimal.h"
#include "EPauseMenuPage.generated.h"

UENUM(BlueprintType)
enum class EPauseMenuPage : uint8 {
    PAGE_INVENTORY,
    PAGE_CHARACTER,
    PAGE_TALENTS,
    PAGE_QUESTS,
    PAGE_MAP,
    PAGE_MAIL,
    PAGE_COLLECTIONS,
    PAGE_CHALLENGES,
    PAGE_SETTINGS,
    PAGE_MAX UMETA(Hidden),
};

