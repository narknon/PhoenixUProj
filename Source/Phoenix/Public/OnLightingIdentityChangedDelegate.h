#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.h"
#include "OnLightingIdentityChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLightingIdentityChanged, ESanctuaryIdentity, OldIdentity, ESanctuaryIdentity, NewIdentity);

