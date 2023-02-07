#pragma once
#include "CoreMinimal.h"
#include "AddOnMeshesChangedDynamicDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddOnMeshesChangedDynamicDelegate, AActor*, Actor);

