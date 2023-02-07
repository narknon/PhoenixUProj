#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicVarBitfield.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicVarBitfield : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicVarBitfield();
};

