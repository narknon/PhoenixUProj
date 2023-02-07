#pragma once
#include "CoreMinimal.h"
#include "HighestEnemyChangedEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHighestEnemyChangedEvent, AActor*, InActorPtr, int32, InLevelDiff);

