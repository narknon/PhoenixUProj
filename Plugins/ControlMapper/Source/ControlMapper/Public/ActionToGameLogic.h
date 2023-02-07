#pragma once
#include "CoreMinimal.h"
#include "InputToGameLogic.h"
#include "ActionToGameLogic.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UActionToGameLogic : public UInputToGameLogic {
    GENERATED_BODY()
public:
    UActionToGameLogic();
};

