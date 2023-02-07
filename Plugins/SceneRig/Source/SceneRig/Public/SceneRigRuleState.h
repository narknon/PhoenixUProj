#pragma once
#include "CoreMinimal.h"
#include "TimeRigRuleState.h"
#include "SceneRigRuleState.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigRuleState : public UTimeRigRuleState {
    GENERATED_BODY()
public:
    USceneRigRuleState();
};

