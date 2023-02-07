#pragma once
#include "CoreMinimal.h"
#include "EFriendInvitationState.generated.h"

UENUM(BlueprintType)
enum class EFriendInvitationState : uint8 {
    FRIEND_INVITE_STATE_OPEN,
    FRIEND_INVITE_STATE_ACCEPTED,
    FRIEND_INVITE_STATE_CANCELLED,
    FRIEND_INVITE_STATE_DECLINED,
    FRIEND_INVITE_STATE_MAX UMETA(Hidden),
};

