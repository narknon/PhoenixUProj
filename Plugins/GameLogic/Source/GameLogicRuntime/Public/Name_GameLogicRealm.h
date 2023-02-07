#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicRealm.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicRealm : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicRealm();
};

