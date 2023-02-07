#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameLogicBase.generated.h"

UCLASS(Abstract, Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicBase : public UObject {
    GENERATED_BODY()
public:
    UGameLogicBase();
};

