#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphTriggerActive_InitializeType.h"
#include "EStoryGraphTrigger_ActivateType.h"
#include "ETimeRig_StoryGraphEdgeFeedbackType.h"
#include "StoryGraphTriggerProvider.h"
#include "TimeRigEventReference.h"
#include "StoryGraphTrigger_Activate.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphTrigger_Activate : public UStoryGraphTriggerProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStoryGraphTriggerActive_InitializeType InitializationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStoryGraphTrigger_ActivateType ActivationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference ActivationEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRig_StoryGraphEdgeFeedbackType FeedbackType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference FeedbackEvent;
    
    UStoryGraphTrigger_Activate();
};

