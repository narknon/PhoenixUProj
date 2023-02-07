#pragma once
#include "CoreMinimal.h"
#include "BudgeterPayload.h"
#include "AmbientPaintingBudgeterPayload.generated.h"

USTRUCT(BlueprintType)
struct FAmbientPaintingBudgeterPayload : public FBudgeterPayload {
    GENERATED_BODY()
public:
    PHOENIX_API FAmbientPaintingBudgeterPayload();
};

