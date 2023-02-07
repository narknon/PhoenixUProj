#pragma once
#include "CoreMinimal.h"
#include "EKnowledgeLevel.generated.h"

UENUM(BlueprintType)
enum class EKnowledgeLevel : uint8 {
    Unknown,
    Level0,
    Level1,
    Level2,
    Level3,
    Level4,
    Level5,
    Completed,
    Secret,
    Unspecified,
};

