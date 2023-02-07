#pragma once
#include "CoreMinimal.h"
#include "EUIGameOverReason.generated.h"

UENUM(BlueprintType)
enum class EUIGameOverReason : uint8 {
    GameOver_Death,
    GameOver_Azkaban,
    GameOver_MissionFailed,
    GameOver_None,
    GameOver_MAX UMETA(Hidden),
};

