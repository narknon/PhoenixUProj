#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.h"
#include "OnLightingIdentityBlendUpdateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLightingIdentityBlendUpdate, ESanctuaryIdentity, OldIdentity, ESanctuaryIdentity, NewIdentity, float, BlendWeight);

