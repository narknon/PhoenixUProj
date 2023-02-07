#pragma once
#include "CoreMinimal.h"
#include "EChromaSDKDeviceTypeEnum.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKDeviceTypeEnum {
    enum Type {
        DE_1D,
        DE_2D,
        DE_MAX UMETA(Hidden),
    };
}

