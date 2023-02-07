#pragma once
#include "CoreMinimal.h"
#include "EMissionComplete.generated.h"

UENUM(BlueprintType)
enum class EMissionComplete : uint8 {
    Complete,
    NotComplete,
};

