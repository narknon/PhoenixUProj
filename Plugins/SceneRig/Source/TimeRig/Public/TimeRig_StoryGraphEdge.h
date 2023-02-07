#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETimeRig_StoryGraphEdgeFeedbackType.h"
#include "ETimeRig_StoryGraphEdgeInitType.h"
#include "ETimeRig_StoryGraphEdgeTriggerType.h"
#include "TimeRigEventReference.h"
#include "TimeRig_StoryGraphEdge.generated.h"

class UStoryGraphConditionProvider;
class UStoryGraphTriggerProvider;
class UTimeRig_StoryGraphNode;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRig_StoryGraphEdge : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStoryGraphConditionProvider* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStoryGraphTriggerProvider* Trigger;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRig_StoryGraphEdgeInitType InitializationType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference InitializationEvent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRig_StoryGraphEdgeTriggerType TriggerType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BranchID;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference ActivationEvent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRig_StoryGraphEdgeFeedbackType FeedbackType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference FeedbackEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig_StoryGraphNode* StartNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig_StoryGraphNode* EndNode;
    
    UTimeRig_StoryGraphEdge();
};

