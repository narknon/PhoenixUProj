#pragma once
#include "CoreMinimal.h"
#include "EMaterialSwapSphereSelectionActorEventType.h"
#include "MaterialSwapSphereSelectionActorEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMaterialSwapSphereSelectionActorEvent, AActor*, Actor, EMaterialSwapSphereSelectionActorEventType, Event);

