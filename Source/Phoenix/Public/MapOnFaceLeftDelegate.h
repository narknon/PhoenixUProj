#pragma once
#include "CoreMinimal.h"
#include "MapOnFaceLeftDelegate.generated.h"

class UMapResponse;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapOnFaceLeft, UMapResponse*, Response);

