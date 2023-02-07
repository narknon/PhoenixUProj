#pragma once
#include "CoreMinimal.h"
#include "EMissionLine.generated.h"

UENUM(BlueprintType)
enum class EMissionLine : uint8 {
    Main,
    Side,
    Assignment,
    Relationship,
    Utility,
    Skip,
    DevelopmentOnly,
};

