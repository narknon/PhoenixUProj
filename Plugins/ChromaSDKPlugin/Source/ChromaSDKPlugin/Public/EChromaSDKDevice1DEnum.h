#pragma once
#include "CoreMinimal.h"
#include "EChromaSDKDevice1DEnum.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKDevice1DEnum {
    enum Type {
        DE_ChromaLink,
        DE_Headset,
        DE_Mousepad,
        DE_MAX UMETA(Hidden),
    };
}

