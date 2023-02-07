#pragma once
#include "CoreMinimal.h"
#include "GameLogicPropositional.h"
#include "GameLogicPropositional_Float.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicPropositional_Float : public UGameLogicPropositional {
    GENERATED_BODY()
public:
    UGameLogicPropositional_Float();
protected:
    UFUNCTION(BlueprintCallable)
    void _MemberValueChanged(float NewResult);
    
};

