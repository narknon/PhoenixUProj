#pragma once
#include "CoreMinimal.h"
#include "MapOnFaceRightDelegate.generated.h"

class UMapResponse;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapOnFaceRight, UMapResponse*, Response);

