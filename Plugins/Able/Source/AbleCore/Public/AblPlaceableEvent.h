#pragma once
#include "CoreMinimal.h"
#include "AblAbilityEvent.h"
#include "AblPlaceableEvent.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblPlaceableEvent : public UAblAbilityEvent {
    GENERATED_BODY()
public:
    UAblPlaceableEvent();
};

