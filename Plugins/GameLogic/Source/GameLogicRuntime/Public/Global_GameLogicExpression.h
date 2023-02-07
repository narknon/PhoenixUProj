#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicSentence.h"
#include "Global_GameLogicExpression.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicExpression : public FGlobal_GameLogicSentence {
    GENERATED_BODY()
public:
    FGlobal_GameLogicExpression();
};

