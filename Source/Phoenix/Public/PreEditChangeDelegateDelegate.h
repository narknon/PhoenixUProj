#pragma once
#include "CoreMinimal.h"
#include "PreEditChangeDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPreEditChangeDelegate, const FName&, PropertyName);

