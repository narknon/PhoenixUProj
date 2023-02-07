#pragma once
#include "CoreMinimal.h"
#include "ELeftArmState.h"
#include "LeftArmStateChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLeftArmStateChangedDelegate, TEnumAsByte<ELeftArmState::Type>, LeftArmState);

