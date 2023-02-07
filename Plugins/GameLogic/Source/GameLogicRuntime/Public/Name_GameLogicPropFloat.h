#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicPropFloat.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicPropFloat : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicPropFloat();
};

