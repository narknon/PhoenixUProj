#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicPropositional.h"
#include "Global_GameLogicPropositional_Int32.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicPropositional_Int32 : public FGlobal_GameLogicPropositional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> Values;
    
    FGlobal_GameLogicPropositional_Int32();
};

