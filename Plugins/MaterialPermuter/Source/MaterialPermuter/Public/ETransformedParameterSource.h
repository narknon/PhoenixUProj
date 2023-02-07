#pragma once
#include "CoreMinimal.h"
#include "ETransformedParameterSource.generated.h"

UENUM(BlueprintType)
enum class ETransformedParameterSource : uint8 {
    Actor,
    BoneOrSocket,
    Component,
    None,
};

