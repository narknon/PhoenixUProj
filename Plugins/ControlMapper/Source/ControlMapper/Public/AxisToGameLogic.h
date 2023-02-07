#pragma once
#include "CoreMinimal.h"
#include "InputToGameLogic.h"
#include "AxisToGameLogic.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UAxisToGameLogic : public UInputToGameLogic {
    GENERATED_BODY()
public:
    UAxisToGameLogic();
};

