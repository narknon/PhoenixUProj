#pragma once
#include "CoreMinimal.h"
#include "AssetBlendDomainVisibiltyDelegateDelegate.generated.h"

class UAssetBlendDomainDelegateVisibilityComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAssetBlendDomainVisibiltyDelegate, UAssetBlendDomainDelegateVisibilityComponent*, BlendDomainVisibilityComponent, bool, bIsVisible, float, Alpha);

