#pragma once
#include "CoreMinimal.h"
#include "CollectedForageableDelegateDelegate.generated.h"

class AForagable;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCollectedForageableDelegate, AForagable*, InActor);

