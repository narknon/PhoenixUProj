#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicPropositional.h"
#include "Global_GameLogicPropositional_String.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicPropositional_String : public FGlobal_GameLogicPropositional {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Values;
    
    FGlobal_GameLogicPropositional_String();
};

