#pragma once
#include "CoreMinimal.h"
#include "ScheduledEntityCreatedDelegate.generated.h"

class UScheduledEntity;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScheduledEntityCreated, const UScheduledEntity*, ScheduledEntity);

