#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.h"
#include "OnIdentityLightTemplateUpdateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnIdentityLightTemplateUpdate, ESanctuaryIdentity, OldIdentity, ESanctuaryIdentity, NewIdentity, float, BlendWeight);

