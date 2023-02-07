#pragma once
#include "CoreMinimal.h"
#include "CombatDelegateDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatDelegate, const ASocialReasoning*, SocialReasoning);

