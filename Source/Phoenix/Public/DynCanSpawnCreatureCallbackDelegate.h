#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DynCanSpawnCreatureCallbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FDynCanSpawnCreatureCallback, bool, bSpawnable, FTransform, InCreatureTransform);

