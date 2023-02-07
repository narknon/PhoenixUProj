#pragma once
#include "CoreMinimal.h"
#include "BudgeterPayload.h"
#include "SceneRigBudgeterPayload.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigBudgeterPayload : public FBudgeterPayload {
    GENERATED_BODY()
public:
    PHOENIXSIGNIFICANCEMANAGER_API FSceneRigBudgeterPayload();
};

