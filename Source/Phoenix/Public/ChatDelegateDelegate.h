#pragma once
#include "CoreMinimal.h"
#include "ChatDelegateDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChatDelegate, const ASocialReasoning*, SocialReasoning);

