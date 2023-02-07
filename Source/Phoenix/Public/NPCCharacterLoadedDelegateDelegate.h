#pragma once
#include "CoreMinimal.h"
#include "NPCCharacterLoadedDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCCharacterLoadedDelegate, AActor*, LoadedActor);

