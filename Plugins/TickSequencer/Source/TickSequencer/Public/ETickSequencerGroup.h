#pragma once
#include "CoreMinimal.h"
#include "ETickSequencerGroup.generated.h"

UENUM(BlueprintType)
enum class ETickSequencerGroup : uint8 {
    PreActorTick,
    PrePhysics,
    DuringPhysics,
    PostPhysics,
    PostUpdateWork,
    PostActorTick,
    Invalid,
};

