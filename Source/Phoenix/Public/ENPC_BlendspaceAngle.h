#pragma once
#include "CoreMinimal.h"
#include "ENPC_BlendspaceAngle.generated.h"

UENUM(BlueprintType)
enum class ENPC_BlendspaceAngle : uint8 {
    Forward,
    Left45,
    Left90,
    Left135,
    Left180,
    Right180,
    Right135,
    Right90,
    Right45,
    ENPC_MAX UMETA(Hidden),
};

