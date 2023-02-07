#pragma once
#include "CoreMinimal.h"
#include "EEnemy_LOSType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_LOSType : uint8 {
    Line,
    Cone,
    SweptSphere,
    EEnemy_MAX UMETA(Hidden),
};

