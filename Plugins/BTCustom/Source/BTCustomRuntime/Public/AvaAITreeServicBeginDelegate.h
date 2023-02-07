#pragma once
#include "CoreMinimal.h"
#include "AvaAITreeServicBeginDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAvaAITreeServicBegin, const AActor*, OwnerActor);

