#pragma once
#include "CoreMinimal.h"
#include "ERightArmState.h"
#include "RightArmStateChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRightArmStateChangedDelegate, TEnumAsByte<ERightArmState::Type>, RightArmState, TEnumAsByte<ERightArmState::Type>, LastRightArmState);

