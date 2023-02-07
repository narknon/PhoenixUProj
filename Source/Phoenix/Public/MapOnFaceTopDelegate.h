#pragma once
#include "CoreMinimal.h"
#include "MapOnFaceTopDelegate.generated.h"

class UMapResponse;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapOnFaceTop, UMapResponse*, Response);

