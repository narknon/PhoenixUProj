#pragma once
#include "CoreMinimal.h"
#include "AIGameEvent.h"
#include "GameEventStartDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameEventStartDelegate, const FAIGameEvent&, InGameEvent);

