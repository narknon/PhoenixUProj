#pragma once
#include "CoreMinimal.h"
#include "OnDodgeDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDodgeDelegate, AActor*, Actor);

