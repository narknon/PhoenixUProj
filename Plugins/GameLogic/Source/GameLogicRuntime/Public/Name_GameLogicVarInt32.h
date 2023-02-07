#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicVarInt32.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicVarInt32 : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicVarInt32();
};

