#pragma once
#include "CoreMinimal.h"
#include "VariantMapHandle.h"
#include "BTCustomActionDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBTCustomActionDelegate, FVariantMapHandle, KeyStruct);

