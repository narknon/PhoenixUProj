#pragma once
#include "CoreMinimal.h"
#include "OnFleshDestroyedDelegate.generated.h"

class AActor;
class UScheduledEntity;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFleshDestroyed, AActor*, Actor, UScheduledEntity*, ScheduledEntity);

