#pragma once
#include "CoreMinimal.h"
#include "EInputContextLogicType.generated.h"

UENUM(BlueprintType)
namespace EInputContextLogicType {
    enum Type {
        Binary,
        Fuzzy,
    };
}

