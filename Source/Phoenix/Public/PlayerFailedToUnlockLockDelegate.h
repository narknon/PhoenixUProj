#pragma once
#include "CoreMinimal.h"
#include "EUnlockFailedReason.h"
#include "PlayerFailedToUnlockLockDelegate.generated.h"

class ALockable;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FPlayerFailedToUnlockLock, ALockable*, Lockable, EUnlockFailedReason, UnlockFailedReason);

