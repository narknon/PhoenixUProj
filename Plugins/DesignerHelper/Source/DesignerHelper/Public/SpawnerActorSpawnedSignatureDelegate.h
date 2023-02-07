#pragma once
#include "CoreMinimal.h"
#include "SpawnerActorSpawnedSignatureDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpawnerActorSpawnedSignature, AActor*, SpawnedActor, const FName&, GroupName);

