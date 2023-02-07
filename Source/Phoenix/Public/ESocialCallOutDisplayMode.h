#pragma once
#include "CoreMinimal.h"
#include "ESocialCallOutDisplayMode.generated.h"

UENUM(BlueprintType)
namespace ESocialCallOutDisplayMode {
    enum Type {
        None,
        Name,
        Stations,
        SocialCapital,
        Schedule,
        All,
        Travel,
    };
}

