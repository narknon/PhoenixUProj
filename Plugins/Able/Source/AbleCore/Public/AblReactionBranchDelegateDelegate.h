#pragma once
#include "CoreMinimal.h"
#include "AblReactionBranchDelegateDelegate.generated.h"

class UAblAbilityContext;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAblReactionBranchDelegate, const UAblAbilityContext*, CurrentContext, const UAblAbilityContext*, NextContext);

