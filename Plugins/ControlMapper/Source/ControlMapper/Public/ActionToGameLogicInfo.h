#pragma once
#include "CoreMinimal.h"
#include "InputToGameLogicInfo.h"
#include "ActionToGameLogicInfo.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FActionToGameLogicInfo : public FInputToGameLogicInfo {
    GENERATED_BODY()
public:
    FActionToGameLogicInfo();
};

