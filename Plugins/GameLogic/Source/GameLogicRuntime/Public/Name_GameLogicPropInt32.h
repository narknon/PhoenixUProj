#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicPropInt32.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicPropInt32 : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicPropInt32();
};

