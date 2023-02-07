#pragma once
#include "CoreMinimal.h"
#include "EChromaSDKStreamStatusEnum.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKStreamStatusEnum {
    enum Type {
        READY,
        AUTHORIZING,
        BROADCASTING,
        WATCHING,
        NOT_AUTHORIZED,
        BROADCAST_DUPLICATE,
        SERVICE_OFFLINE,
    };
}

