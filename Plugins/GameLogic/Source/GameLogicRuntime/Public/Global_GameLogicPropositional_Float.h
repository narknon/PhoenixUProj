#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicPropositional.h"
#include "Global_GameLogicPropositional_Float.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicPropositional_Float : public FGlobal_GameLogicPropositional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> Values;
    
    FGlobal_GameLogicPropositional_Float();
};

