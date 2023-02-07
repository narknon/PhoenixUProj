#pragma once
#include "CoreMinimal.h"
#include "StairStatusChangedDelegateDelegate.generated.h"

class UFlyingStairComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FStairStatusChangedDelegate, UFlyingStairComponent*, FlyingStairComponent, float, animationLength, float, animationStartPosition);

