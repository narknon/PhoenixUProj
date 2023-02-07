#pragma once
#include "CoreMinimal.h"
#include "EWindSourceEnvelopeTriggerEvent.h"
#include "WindSourceEnvelopeRetriggerDelegate.generated.h"

class UWindEnvelopeController;
class UWindSourceComponentBase;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FWindSourceEnvelopeRetrigger, UWindSourceComponentBase*, WindSourceComponent, const UWindEnvelopeController*, WindEnvelopeController, EWindSourceEnvelopeTriggerEvent, EnvelopeRetriggerEvent);

