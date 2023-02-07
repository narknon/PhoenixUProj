#pragma once
#include "CoreMinimal.h"
#include "InfirmaryEventDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInfirmaryEventDelegate, const FString&, UniqueId);

