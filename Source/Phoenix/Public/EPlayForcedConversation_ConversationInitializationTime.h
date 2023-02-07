#pragma once
#include "CoreMinimal.h"
#include "EPlayForcedConversation_ConversationInitializationTime.generated.h"

UENUM(BlueprintType)
enum class EPlayForcedConversation_ConversationInitializationTime : uint8 {
    WhenCreatingState,
    WhenEnteringAction,
    EPlayForcedConversation_MAX UMETA(Hidden),
};

