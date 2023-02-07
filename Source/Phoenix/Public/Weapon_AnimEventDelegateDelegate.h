#pragma once
#include "CoreMinimal.h"
#include "Weapon_AnimEventDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWeapon_AnimEventDelegate, FName, Name);

