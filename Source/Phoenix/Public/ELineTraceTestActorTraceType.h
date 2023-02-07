#pragma once
#include "CoreMinimal.h"
#include "ELineTraceTestActorTraceType.generated.h"

UENUM(BlueprintType)
enum class ELineTraceTestActorTraceType : uint8 {
    Channel,
    ObjectType,
    Profile,
};

