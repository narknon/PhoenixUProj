#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphTrigger_InitializeType.h"
#include "ETimeRig_StoryGraphEdgeFeedbackType.h"
#include "StoryGraphTriggerProvider.h"
#include "TimeRigEventReference.h"
#include "StoryGraphTrigger_Initialize.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphTrigger_Initialize : public UStoryGraphTriggerProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStoryGraphTrigger_InitializeType InitializationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference InitializationEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRig_StoryGraphEdgeFeedbackType FeedbackType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference FeedbackEvent;
    
    UStoryGraphTrigger_Initialize();
};

