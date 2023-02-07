#pragma once
#include "CoreMinimal.h"
#include "OnFleshCreatedDelegate.generated.h"

class AActor;
class UScheduledEntity;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFleshCreated, AActor*, Actor, UScheduledEntity*, ScheduledEntity);

