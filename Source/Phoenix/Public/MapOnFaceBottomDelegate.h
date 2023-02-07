#pragma once
#include "CoreMinimal.h"
#include "MapOnFaceBottomDelegate.generated.h"

class UMapResponse;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapOnFaceBottom, UMapResponse*, Response);

