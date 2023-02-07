#pragma once
#include "CoreMinimal.h"
#include "MapOnDPadLeftDelegate.generated.h"

class UMapResponse;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapOnDPadLeft, UMapResponse*, Response);

