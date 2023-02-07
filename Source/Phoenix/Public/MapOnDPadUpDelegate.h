#pragma once
#include "CoreMinimal.h"
#include "MapOnDPadUpDelegate.generated.h"

class UMapResponse;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapOnDPadUp, UMapResponse*, Response);

