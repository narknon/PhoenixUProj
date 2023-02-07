#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicSentence.h"
#include "Global_GameLogicPropositional.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicPropositional : public FGlobal_GameLogicSentence {
    GENERATED_BODY()
public:
    FGlobal_GameLogicPropositional();
};

