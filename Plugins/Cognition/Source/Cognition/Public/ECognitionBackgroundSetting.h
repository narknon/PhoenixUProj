#pragma once
#include "CoreMinimal.h"
#include "ECognitionBackgroundSetting.generated.h"

UENUM(BlueprintType)
enum class ECognitionBackgroundSetting : uint8 {
    NotInBackground,
    InBackgroundNoBest,
    InBackgroundShowBest,
};

