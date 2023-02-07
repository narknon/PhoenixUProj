#pragma once
#include "CoreMinimal.h"
#include "AcknowledgeEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAcknowledgeEvent, FName, AcknowledgementID);

