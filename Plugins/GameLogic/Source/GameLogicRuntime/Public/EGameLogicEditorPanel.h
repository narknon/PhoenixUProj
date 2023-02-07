#pragma once
#include "CoreMinimal.h"
#include "EGameLogicEditorPanel.generated.h"

UENUM(BlueprintType)
enum class EGameLogicEditorPanel : uint8 {
    BoolVars,
    Int32Vars,
    Int32Props,
    FloatVars,
    FloatProps,
    Expressions,
    TimerVars,
    EnumVars,
    EnumPropz,
    StringVars,
    StringProps,
    BitfieldVars,
    BitfieldProps,
};

