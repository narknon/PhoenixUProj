#pragma once
#include "CoreMinimal.h"
#include "EProcessBestFlag.generated.h"

UENUM(BlueprintType)
namespace EProcessBestFlag {
    enum Type {
        TargetSighted,
        TargetLost,
    };
}

