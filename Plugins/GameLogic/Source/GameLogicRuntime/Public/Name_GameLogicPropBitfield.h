#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicPropBitfield.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicPropBitfield : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicPropBitfield();
};

