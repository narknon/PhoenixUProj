#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicExpression.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicExpression : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicExpression();
};

