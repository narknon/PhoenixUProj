#pragma once
#include "CoreMinimal.h"
#include "SurfaceTypeChanged.h"
#include "HermesSurfaceTypeChangedDelegateDelegate.generated.h"

class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FHermesSurfaceTypeChangedDelegate, const UObject*, Caller, const FSurfaceTypeChanged&, SurfaceTypeChanged);

