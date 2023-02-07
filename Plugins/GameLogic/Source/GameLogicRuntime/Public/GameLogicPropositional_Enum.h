#pragma once
#include "CoreMinimal.h"
#include "GameLogicPropositional.h"
#include "GameLogicPropositional_Enum.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicPropositional_Enum : public UGameLogicPropositional {
    GENERATED_BODY()
public:
    UGameLogicPropositional_Enum();
protected:
    UFUNCTION(BlueprintCallable)
    void _MemberValueChanged(uint8 NewResult);
    
};

