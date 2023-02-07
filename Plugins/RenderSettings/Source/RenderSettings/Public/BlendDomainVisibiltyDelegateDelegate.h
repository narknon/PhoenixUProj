#pragma once
#include "CoreMinimal.h"
#include "BlendDomainVisibiltyDelegateDelegate.generated.h"

class UBlendDomainDelegateVisibilityComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBlendDomainVisibiltyDelegate, UBlendDomainDelegateVisibilityComponent*, BlendDomainVisibilityComponent, bool, bIsVisible, float, Alpha);

