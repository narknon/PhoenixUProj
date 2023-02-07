#pragma once
#include "CoreMinimal.h"
#include "EBulletinBoardType.generated.h"

UENUM(BlueprintType)
enum EBulletinBoardType {
    BULLETIN_BOARD_TYPE_HOGWARTS,
    BULLETIN_BOARD_TYPE_HOGSMEADE,
    BULLETIN_BOARD_TYPE_ROOKWOOD_THIEF,
    BULLETIN_BOARD_TYPE_ROOKWOOD_POACHER,
    BULLETIN_BOARD_TYPE_MAX UMETA(Hidden),
};

