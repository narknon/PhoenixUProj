#pragma once
#include "CoreMinimal.h"
#include "EEnemy_StimulusType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_StimulusType : uint8 {
    None,
    FinisherAnticipate,
    FinisherAware,
    FinisherReact,
    EEnemy_MAX UMETA(Hidden),
};

