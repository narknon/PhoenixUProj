#pragma once
#include "CoreMinimal.h"
#include "ELineTraceTestActorQueryMobilityType.generated.h"

UENUM(BlueprintType)
enum class ELineTraceTestActorQueryMobilityType : uint8 {
    Any,
    Static,
    Dynamic,
};

