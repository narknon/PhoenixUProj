#pragma once
#include "CoreMinimal.h"
#include "EChromaSDKDeviceEnum.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKDeviceEnum {
    enum Type {
        DE_ChromaLink,
        DE_Headset,
        DE_Keyboard,
        DE_Keypad,
        DE_Mouse,
        DE_Mousepad,
        DE_MAX UMETA(Hidden),
    };
}

