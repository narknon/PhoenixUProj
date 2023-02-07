#pragma once
#include "CoreMinimal.h"
#include "EUtilityTrackedErrorType.generated.h"

UENUM(BlueprintType)
enum class EUtilityTrackedErrorType : uint8 {
    Error_Unspecified,
    Error_InvalidActor,
    Error_InvalidPath,
    Error_MissingNavmesh,
    Error_MAX UMETA(Hidden),
};

