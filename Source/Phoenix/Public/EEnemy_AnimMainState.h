#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AnimMainState.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AnimMainState : uint8 {
    None,
    React,
    Abort,
    Dead,
    EEnemy_MAX UMETA(Hidden),
};

