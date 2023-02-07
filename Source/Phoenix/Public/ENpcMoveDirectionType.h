#pragma once
#include "CoreMinimal.h"
#include "ENpcMoveDirectionType.generated.h"

UENUM(BlueprintType)
enum class ENpcMoveDirectionType : uint8 {
    Global,
    Local,
};

