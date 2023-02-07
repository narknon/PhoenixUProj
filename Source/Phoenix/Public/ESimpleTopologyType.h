#pragma once
#include "CoreMinimal.h"
#include "ESimpleTopologyType.generated.h"

UENUM(BlueprintType)
enum class ESimpleTopologyType : uint8 {
    Init,
    PendingCompute,
    Surface,
    Interior,
    EmptySpace,
    Error,
};

