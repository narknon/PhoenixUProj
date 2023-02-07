#pragma once
#include "CoreMinimal.h"
#include "ELightOnOffFXTargetMode.generated.h"

UENUM(BlueprintType)
enum class ELightOnOffFXTargetMode : uint8 {
    UseParentOnOff,
    UseComponentOnOff,
    ChildrenThatMatchParent,
    ChildrenThatOpposeParent,
};

