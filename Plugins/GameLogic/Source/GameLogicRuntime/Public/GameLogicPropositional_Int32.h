#pragma once
#include "CoreMinimal.h"
#include "GameLogicPropositional.h"
#include "GameLogicPropositional_Int32.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicPropositional_Int32 : public UGameLogicPropositional {
    GENERATED_BODY()
public:
    UGameLogicPropositional_Int32();
protected:
    UFUNCTION(BlueprintCallable)
    void _MemberValueChanged(int32 NewResult);
    
};

