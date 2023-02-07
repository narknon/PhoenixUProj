#pragma once
#include "CoreMinimal.h"
#include "AblReactionContextDelegateDelegate.generated.h"

class UAblAbilityContext;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAblReactionContextDelegate, const UAblAbilityContext*, Context);

