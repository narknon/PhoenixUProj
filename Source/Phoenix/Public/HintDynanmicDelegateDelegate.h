#pragma once
#include "CoreMinimal.h"
#include "HintDynanmicDelegateDelegate.generated.h"

class UHint;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(bool, FHintDynanmicDelegate, UHint*, HintToDisplay);

