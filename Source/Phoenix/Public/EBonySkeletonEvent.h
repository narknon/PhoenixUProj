#pragma once
#include "CoreMinimal.h"
#include "EBonySkeletonEvent.generated.h"

UENUM(BlueprintType)
enum class EBonySkeletonEvent : uint8 {
    SkeletonVisible,
    NonSkeletonHidden,
};

