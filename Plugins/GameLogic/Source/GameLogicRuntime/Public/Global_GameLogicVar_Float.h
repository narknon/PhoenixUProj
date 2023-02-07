#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicElement.h"
#include "Global_GameLogicVar_Float.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicVar_Float : public FGlobal_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialValue;
    
    FGlobal_GameLogicVar_Float();
};

