#pragma once
#include "CoreMinimal.h"
#include "MapOnDPadDownDelegate.generated.h"

class UMapResponse;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapOnDPadDown, UMapResponse*, Response);

