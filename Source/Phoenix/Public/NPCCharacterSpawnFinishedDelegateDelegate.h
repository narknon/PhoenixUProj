#pragma once
#include "CoreMinimal.h"
#include "NPCCharacterSpawnFinishedDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCCharacterSpawnFinishedDelegate, AActor*, SpawnedActor);

