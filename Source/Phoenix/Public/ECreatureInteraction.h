#pragma once
#include "CoreMinimal.h"
#include "ECreatureInteraction.generated.h"

UENUM(BlueprintType)
enum class ECreatureInteraction : uint8 {
    None,
    Pet,
    Play,
};

