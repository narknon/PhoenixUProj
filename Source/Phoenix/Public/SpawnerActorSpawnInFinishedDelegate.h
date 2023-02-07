#pragma once
#include "CoreMinimal.h"
#include "SpawnerActorSpawnInFinishedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnerActorSpawnInFinished, AActor*, SpawnedActor);

