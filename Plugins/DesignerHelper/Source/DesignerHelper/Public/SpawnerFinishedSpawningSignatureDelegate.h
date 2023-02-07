#pragma once
#include "CoreMinimal.h"
#include "SpawnerFinishedSpawningSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnerFinishedSpawningSignature, const FName&, GroupName);

