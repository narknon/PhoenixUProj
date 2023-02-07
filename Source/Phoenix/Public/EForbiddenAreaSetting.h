#pragma once
#include "CoreMinimal.h"
#include "EForbiddenAreaSetting.generated.h"

UENUM(BlueprintType)
enum class EForbiddenAreaSetting : uint8 {
    All,
    Male,
    Female,
    SpecificNPC,
};

