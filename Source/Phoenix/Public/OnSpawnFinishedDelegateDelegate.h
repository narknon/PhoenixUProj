#pragma once
#include "CoreMinimal.h"
#include "OnSpawnFinishedDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawnFinishedDelegate, AActor*, pActor);

