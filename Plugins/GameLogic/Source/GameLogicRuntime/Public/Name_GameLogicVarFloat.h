#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicVarFloat.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicVarFloat : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicVarFloat();
};

