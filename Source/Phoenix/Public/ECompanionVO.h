#pragma once
#include "CoreMinimal.h"
#include "ECompanionVO.generated.h"

UENUM(BlueprintType)
enum class ECompanionVO : uint8 {
    JoinAvatar,
    FollowAvatarAgain,
    WaitforAvatar,
    AvatarDismisses,
    HealsPlayer,
    PlayerDying,
    PlayerHealsCompanion,
    ScheduleConflictDismiss,
    Reject,
    Stealth,
    Dying,
    PlayerHit,
    PlayerHitDismissWarning,
    Num,
};

