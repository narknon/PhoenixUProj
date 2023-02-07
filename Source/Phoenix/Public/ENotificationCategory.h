#pragma once
#include "CoreMinimal.h"
#include "ENotificationCategory.generated.h"

UENUM(BlueprintType)
enum class ENotificationCategory : uint8 {
    NotificationCategory_Celebration,
    NotificationCategory_CelebrationMed,
    NotificationCategory_MissionBanner,
    NotificationCategory_MissionStep,
    NotificationCategory_LevelUp,
    NotificationCategory_Pickups,
    NotificationCategory_Knowledge,
    NotificationCategory_OwlMail,
    NotificationCategory_XP,
    NotificationCategory_SmallText,
    NotificationCategory_All,
    NotificationCategory_MAX UMETA(Hidden),
};

