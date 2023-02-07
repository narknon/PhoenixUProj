#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicVarTimer.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicVarTimer : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicVarTimer();
};

