#pragma once
#include "CoreMinimal.h"
#include "DbAssetActorSpawnFinishedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FDbAssetActorSpawnFinished, AActor*, SpawnedActor);

