#pragma once
#include "CoreMinimal.h"
#include "EConversationTransformType.generated.h"

UENUM(BlueprintType)
enum class EConversationTransformType : uint8 {
    Initial,
    InitialAvatarRoot,
    FinalInteractionActorRoot,
    Final,
};

