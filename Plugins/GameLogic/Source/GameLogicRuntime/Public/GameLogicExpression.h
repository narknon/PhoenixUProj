#pragma once
#include "CoreMinimal.h"
#include "GameLogicSentence.h"
#include "GameLogicExpression.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicExpression : public UGameLogicSentence {
    GENERATED_BODY()
public:
    UGameLogicExpression();
protected:
    UFUNCTION(BlueprintCallable)
    void _MemberValueChanged(bool NewResult);
    
};

