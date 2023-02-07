#pragma once
#include "CoreMinimal.h"
#include "ClothMountTargets.h"
#include "OnClothTargetsStartDelegate.generated.h"

class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_FourParams(FOnClothTargetsStart, const FClothMountTargets&, ClothMountTargets, UObject*, Caller, bool, BlendIn, bool, TargetsOnly);

