#pragma once
#include "CoreMinimal.h"
#include "EUIQActionBarType.generated.h"

UENUM(BlueprintType)
enum class EUIQActionBarType : uint8 {
    QuickAction_Spells,
    QuickAction_Inventory,
    QuickAction_None,
    QuickAction_MAX UMETA(Hidden),
};

