#pragma once
#include "CoreMinimal.h"
#include "EChromaSDKDevice2DEnum.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKDevice2DEnum {
    enum Type {
        DE_Keyboard,
        DE_Keypad,
        DE_Mouse,
        DE_MAX UMETA(Hidden),
    };
}

