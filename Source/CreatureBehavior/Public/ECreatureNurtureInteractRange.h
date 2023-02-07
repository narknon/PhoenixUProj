#pragma once
#include "CoreMinimal.h"
#include "ECreatureNurtureInteractRange.generated.h"

UENUM(BlueprintType)
enum class ECreatureNurtureInteractRange : uint8 {
    Close,
    Normal,
    Far,
};

