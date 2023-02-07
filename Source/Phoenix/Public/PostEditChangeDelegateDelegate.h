#pragma once
#include "CoreMinimal.h"
#include "PostEditChangeDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostEditChangeDelegate, const FName&, PropertyName);

