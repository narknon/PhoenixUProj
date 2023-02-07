#pragma once
#include "CoreMinimal.h"
#include "ETargetMethod.generated.h"

UENUM(BlueprintType)
namespace ETargetMethod {
    enum Type {
        None,
        Replace,
        Stack,
    };
}

