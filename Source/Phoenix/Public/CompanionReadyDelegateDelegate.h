#pragma once
#include "CoreMinimal.h"
#include "CompanionReadyDelegateDelegate.generated.h"

class UScheduledEntity;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompanionReadyDelegate, const UScheduledEntity*, ScheduledEntity);

