#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ArrivedEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FArrivedEvent, AActor*, Actor, FVector, Loc);

