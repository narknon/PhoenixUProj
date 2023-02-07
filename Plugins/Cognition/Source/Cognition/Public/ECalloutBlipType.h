#pragma once
#include "CoreMinimal.h"
#include "ECalloutBlipType.generated.h"

UENUM(BlueprintType)
enum class ECalloutBlipType : uint8 {
    Diamond,
    Dot,
    Door,
    Vendor,
    FastTravel,
};

