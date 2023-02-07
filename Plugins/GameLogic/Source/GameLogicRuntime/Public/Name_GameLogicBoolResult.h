#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicElement.h"
#include "Name_GameLogicBoolResult.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FName_GameLogicBoolResult : public FName_GameLogicElement {
    GENERATED_BODY()
public:
    FName_GameLogicBoolResult();
};
FORCEINLINE uint32 GetTypeHash(const FName_GameLogicBoolResult) { return 0; }

