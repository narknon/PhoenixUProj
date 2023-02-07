#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicElement.h"
#include "Global_GameLogicSentence.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicSentence : public FGlobal_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> LogicElements;
    
    FGlobal_GameLogicSentence();
};

