#pragma once
#include "CoreMinimal.h"
#include "CompanionshipDelegateDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompanionshipDelegate, const ASocialReasoning*, SocialReasoning);

