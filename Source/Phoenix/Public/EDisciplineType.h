#pragma once
#include "CoreMinimal.h"
#include "EDisciplineType.generated.h"

UENUM(BlueprintType)
enum class EDisciplineType : uint8 {
    NONE,
    Arithmancy,
    Astronomy,
    Beasts,
    Charms,
    DarkArts,
    DefenceAgainstTheDarkArts,
    Divination,
    Flying,
    Herbology,
    HistoryOfMagic,
    Infiltrator,
    Potions,
    Socialite,
    Transfiguration,
    ALL_DISCIPLINES,
};

