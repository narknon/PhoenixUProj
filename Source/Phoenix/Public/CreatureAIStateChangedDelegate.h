#pragma once
#include "CoreMinimal.h"
#include "ECreatureAIState.h"
#include "CreatureAIStateChangedDelegate.generated.h"

class UCreature_AIComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCreatureAIStateChanged, UCreature_AIComponent*, AIComponent, ECreatureAIState, PrevAIState);

