#pragma once
#include "CoreMinimal.h"
#include "CustomizableActorLoadedOutputPinDelegate.generated.h"

class ACustomizableActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCustomizableActorLoadedOutputPin, ACustomizableActor*, Actor);

