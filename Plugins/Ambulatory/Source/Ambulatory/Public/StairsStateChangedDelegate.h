#pragma once
#include "CoreMinimal.h"
#include "EStairsState.h"
#include "StairsStateChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStairsStateChanged, TEnumAsByte<EStairsState::Type>, LastStairsState, TEnumAsByte<EStairsState::Type>, NewStairsState);

