#pragma once
#include "CoreMinimal.h"
#include "EConversationType.generated.h"

UENUM(BlueprintType)
enum class EConversationType : uint8 {
    Vendor,
    Greeting,
    Critical,
    VendorUpdate,
    Update,
    Standard,
    VO,
};

