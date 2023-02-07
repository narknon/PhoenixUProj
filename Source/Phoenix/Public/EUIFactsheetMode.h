#pragma once
#include "CoreMinimal.h"
#include "EUIFactsheetMode.generated.h"

UENUM(BlueprintType)
enum class EUIFactsheetMode : uint8 {
    UI_Compendium,
    UI_Book,
    UI_Person,
    UI_MAX UMETA(Hidden),
};

