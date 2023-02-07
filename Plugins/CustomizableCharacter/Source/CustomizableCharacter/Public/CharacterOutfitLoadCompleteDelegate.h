#pragma once
#include "CoreMinimal.h"
#include "CharacterOutfitLoadCompleteDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterOutfitLoadComplete, AActor*, Actor, FName, OutfitID);

