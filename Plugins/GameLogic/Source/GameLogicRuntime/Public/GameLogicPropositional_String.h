#pragma once
#include "CoreMinimal.h"
#include "GameLogicPropositional.h"
#include "GameLogicPropositional_String.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicPropositional_String : public UGameLogicPropositional {
    GENERATED_BODY()
public:
    UGameLogicPropositional_String();
protected:
    UFUNCTION(BlueprintCallable)
    void _MemberValueChanged(const FString& NewResult);
    
};

