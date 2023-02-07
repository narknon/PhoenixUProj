#pragma once
#include "CoreMinimal.h"
#include "ETimedAbilityRetriggerBehaviour.generated.h"

UENUM(BlueprintType)
enum ETimedAbilityRetriggerBehaviour {
    Restart,
    Delay_IgnoreActive,
    Delay_ExtendActive,
    Ignore,
};

