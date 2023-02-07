#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicVarEnum.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicVarEnum : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicVarEnum();
};

