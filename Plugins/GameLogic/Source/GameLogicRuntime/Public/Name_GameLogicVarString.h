#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicVarString.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicVarString : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicVarString();
};

