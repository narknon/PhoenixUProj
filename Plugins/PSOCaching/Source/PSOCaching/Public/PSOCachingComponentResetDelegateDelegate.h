#pragma once
#include "CoreMinimal.h"
#include "PSOCachingComponentResetDelegateDelegate.generated.h"

class UPrimitiveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FPSOCachingComponentResetDelegate, UPrimitiveComponent*, Primitive);

