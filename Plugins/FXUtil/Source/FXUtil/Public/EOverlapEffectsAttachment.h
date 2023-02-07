#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsAttachment.generated.h"

UENUM(BlueprintType)
enum class EOverlapEffectsAttachment : uint8 {
    Instigator,
    Victim,
    PreferVictimOverInstigator,
    PreferInstigatorOverVictim,
};

