#pragma once
#include "CoreMinimal.h"
#include "ECalloutType.generated.h"

UENUM(BlueprintType)
enum class ECalloutType : uint8 {
    Interact,
    Interact_Blip_Action,
    Interact_Blip_Action_Descriptor,
    Interact_Blip_Descriptor,
    Interact_NoBlip_Action,
};

