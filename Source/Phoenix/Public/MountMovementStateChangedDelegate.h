#pragma once
#include "CoreMinimal.h"
#include "EMountMovementState.h"
#include "MountMovementStateChangedDelegate.generated.h"

class UCreature_MountComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMountMovementStateChanged, UCreature_MountComponent*, MountComponent, EMountMovementState, PrevMovementState);

