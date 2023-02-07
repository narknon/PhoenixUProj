#pragma once
#include "CoreMinimal.h"
#include "GameLogicSentence.h"
#include "GameLogicPropositional.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicPropositional : public UGameLogicSentence {
    GENERATED_BODY()
public:
    UGameLogicPropositional();
};

