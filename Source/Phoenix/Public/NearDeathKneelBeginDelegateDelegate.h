#pragma once
#include "CoreMinimal.h"
#include "NearDeathKneelBeginDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNearDeathKneelBeginDelegate, AActor*, Owner);

