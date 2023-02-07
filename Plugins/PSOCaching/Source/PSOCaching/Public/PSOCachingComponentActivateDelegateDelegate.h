#pragma once
#include "CoreMinimal.h"
#include "PSOCachingComponentActivateDelegateDelegate.generated.h"

class UObject;
class UPrimitiveComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FPSOCachingComponentActivateDelegate, UPrimitiveComponent*, Primitive, UObject*, Asset);

