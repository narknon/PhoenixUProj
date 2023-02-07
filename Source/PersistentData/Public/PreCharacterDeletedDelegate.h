#pragma once
#include "CoreMinimal.h"
#include "PreCharacterDeletedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPreCharacterDeleted, int32, CharacterID);

