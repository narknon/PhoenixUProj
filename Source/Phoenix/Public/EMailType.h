#pragma once
#include "CoreMinimal.h"
#include "EMailType.generated.h"

UENUM(BlueprintType)
enum EMailType {
    MAIL_TYPE_LETTER,
    MAIL_TYPE_BULLETIN_BOARD_POST,
    MAIL_TYPE_HOGSMEADE_POST,
    MAIL_TYPE_THIEF_POST,
    MAIL_TYPE_POACHER_POST,
    MAIL_TYPE_SHOP_POST,
    MAIL_TYPE_POSTER,
    MAIL_TYPE_COUNT,
    MAIL_TYPE_MAX UMETA(Hidden),
};

