#pragma once
#include "CoreMinimal.h"
#include "EGamepadTextInputResult.generated.h"

UENUM(BlueprintType)
enum EGamepadTextInputResult {
    Unsupported,
    AlreadyOpen,
    UtilsAPIFailed,
    FieldToLong,
    DialogFailed,
    StringInvalid,
    DialogClosed,
};

