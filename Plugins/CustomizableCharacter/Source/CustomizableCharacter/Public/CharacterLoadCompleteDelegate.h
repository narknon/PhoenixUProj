#pragma once
#include "CoreMinimal.h"
#include "CharacterLoadCompleteDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterLoadComplete, AActor*, Actor);

