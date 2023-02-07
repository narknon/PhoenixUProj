#pragma once
#include "CoreMinimal.h"
#include "PostEventAsyncOutputPinDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostEventAsyncOutputPin, int32, PlayingID);

