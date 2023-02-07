#pragma once
#include "CoreMinimal.h"
#include "Bitfield256.h"
#include "GameLogicPropositional.h"
#include "GameLogicPropositional_Bitfield.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicPropositional_Bitfield : public UGameLogicPropositional {
    GENERATED_BODY()
public:
    UGameLogicPropositional_Bitfield();
protected:
    UFUNCTION(BlueprintCallable)
    void _MemberValueChanged(FBitfield256 NewResult);
    
};

