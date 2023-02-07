#pragma once
#include "CoreMinimal.h"
#include "ESceneParameterChangeRequestType.generated.h"

UENUM(BlueprintType)
enum class ESceneParameterChangeRequestType : uint8 {
    String,
    Bool,
    Float,
    Object,
    Int,
    Transform,
};

