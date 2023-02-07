#pragma once
#include "CoreMinimal.h"
#include "FoundDoorDelegateDelegate.generated.h"

class ADoor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoundDoorDelegate, ADoor*, Door);

