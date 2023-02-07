#pragma once
#include "CoreMinimal.h"
#include "EUIDisplayMode.generated.h"

UENUM(BlueprintType)
enum class EUIDisplayMode : uint8 {
    UI_Viewing,
    UI_Selling,
    UI_Gifting,
    UI_Finding,
    UI_Transfer,
    UI_AddAction,
    UI_Curriculum,
    UI_None,
    UI_MAX UMETA(Hidden),
};

