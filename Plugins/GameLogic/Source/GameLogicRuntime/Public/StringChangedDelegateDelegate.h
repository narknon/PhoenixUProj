#pragma once
#include "CoreMinimal.h"
#include "StringChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStringChangedDelegate, const FString&, CachedResult);

