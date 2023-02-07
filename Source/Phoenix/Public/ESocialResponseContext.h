#pragma once
#include "CoreMinimal.h"
#include "ESocialResponseContext.generated.h"

UENUM(BlueprintType)
namespace ESocialResponseContext {
    enum Type {
        None,
        InTransit,
        InStation,
    };
}

