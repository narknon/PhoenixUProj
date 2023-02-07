#pragma once
#include "CoreMinimal.h"
#include "SceneRigRuleState.h"
#include "TimeRigCoordinate.h"
#include "DialogueSequenceRuleInstance.h"
#include "SceneRigRuleState_DialogueSequence.generated.h"

UCLASS(Blueprintable)
class USceneRigRuleState_DialogueSequence : public USceneRigRuleState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueSequenceRuleInstance RuleInstance;
    
    USceneRigRuleState_DialogueSequence();
protected:
    UFUNCTION(BlueprintCallable)
    void OnForceFinishChanged(FTimeRigCoordinate PreviousCoordinate, FTimeRigCoordinate CurrentCoordinate);
    
};

