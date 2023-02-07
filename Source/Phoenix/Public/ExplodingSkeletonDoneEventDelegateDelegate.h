#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonDoneEventDelegateDelegate.generated.h"

class AExplodingSkeleton;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExplodingSkeletonDoneEventDelegate, AExplodingSkeleton*, ExplodingSkeleton);

