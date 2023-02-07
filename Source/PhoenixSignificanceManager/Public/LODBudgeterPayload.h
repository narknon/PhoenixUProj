#pragma once
#include "CoreMinimal.h"
#include "BudgeterPayload.h"
#include "LODBudgeterPayload.generated.h"

USTRUCT(BlueprintType)
struct FLODBudgeterPayload : public FBudgeterPayload {
    GENERATED_BODY()
public:
    PHOENIXSIGNIFICANCEMANAGER_API FLODBudgeterPayload();
};

