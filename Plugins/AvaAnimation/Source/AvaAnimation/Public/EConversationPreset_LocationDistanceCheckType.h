#pragma once
#include "CoreMinimal.h"
#include "EConversationPreset_LocationDistanceCheckType.generated.h"

UENUM(BlueprintType)
enum class EConversationPreset_LocationDistanceCheckType : uint8 {
    CheckAll,
    IdealOnly,
    NearOnly,
    TooCloseOnly,
    EConversationPreset_MAX UMETA(Hidden),
};

