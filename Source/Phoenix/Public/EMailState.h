#pragma once
#include "CoreMinimal.h"
#include "EMailState.generated.h"

UENUM(BlueprintType)
enum EMailState {
    MAIL_STATE_PENDING,
    MAIL_STATE_ACTIVE,
    MAIL_STATE_ARCHIVED,
    MAIL_STATE_DELETED_BUT_NEEDED_BY_MISSION,
    MAIL_STATE_MAX UMETA(Hidden),
};

