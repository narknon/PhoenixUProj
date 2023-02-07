#pragma once
#include "CoreMinimal.h"
#include "PopulationT4ActorRequestCompletedDelegate.generated.h"

class ATier4_Actor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FPopulationT4ActorRequestCompleted, ATier4_Actor*, T4Actor);

