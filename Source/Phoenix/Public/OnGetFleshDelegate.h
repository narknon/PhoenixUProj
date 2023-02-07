#pragma once
#include "CoreMinimal.h"
#include "OnGetFleshDelegate.generated.h"

class AActor;
class UScheduledEntity;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetFlesh, AActor*, Actor, UScheduledEntity*, ScheduledEntity);

