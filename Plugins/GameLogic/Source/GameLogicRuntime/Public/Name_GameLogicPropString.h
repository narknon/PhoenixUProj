#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicPropString.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicPropString : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicPropString();
};

