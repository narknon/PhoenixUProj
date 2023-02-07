#pragma once
#include "CoreMinimal.h"
#include "TextInputTextConfirmedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTextInputTextConfirmedEvent, FText, InputText);

