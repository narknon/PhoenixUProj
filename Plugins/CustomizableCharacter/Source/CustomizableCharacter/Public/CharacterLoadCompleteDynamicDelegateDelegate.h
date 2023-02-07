#pragma once
#include "CoreMinimal.h"
#include "CharacterLoadCompleteDynamicDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FCharacterLoadCompleteDynamicDelegate, const AActor*, Actor, const bool, Success);

