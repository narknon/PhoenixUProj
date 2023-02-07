#pragma once
#include "CoreMinimal.h"
#include "ELightOnOffFXTargetType.generated.h"

UENUM(BlueprintType)
enum class ELightOnOffFXTargetType : uint8 {
    ParentOnly,
    ParentLightOnly,
    ChildrenOnly,
    ChildLightsOnly,
    ParentAndChildren,
    ParentAndChildLightsOnly,
};

