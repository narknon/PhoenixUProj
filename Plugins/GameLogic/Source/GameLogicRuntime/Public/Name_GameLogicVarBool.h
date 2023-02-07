#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicVarBool.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicVarBool : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicVarBool();
};

