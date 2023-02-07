#pragma once
#include "CoreMinimal.h"
#include "BudgeterPayload.h"
#include "ClothBudgeterPayload.generated.h"

USTRUCT(BlueprintType)
struct FClothBudgeterPayload : public FBudgeterPayload {
    GENERATED_BODY()
public:
    PHOENIXSIGNIFICANCEMANAGER_API FClothBudgeterPayload();
};

