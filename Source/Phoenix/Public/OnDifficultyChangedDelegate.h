#pragma once
#include "CoreMinimal.h"
#include "EDifficulty.h"
#include "OnDifficultyChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDifficultyChanged, EDifficulty, NewDifficulty);

