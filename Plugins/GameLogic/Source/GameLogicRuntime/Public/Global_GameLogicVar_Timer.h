#pragma once
#include "CoreMinimal.h"
#include "Global_GameLogicElement.h"
#include "Global_GameLogicVar_Timer.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGlobal_GameLogicVar_Timer : public FGlobal_GameLogicElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInitiallyPaused;
    
    FGlobal_GameLogicVar_Timer();
};

