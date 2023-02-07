#pragma once
#include "CoreMinimal.h"
#include "StoryGraphTriggerProvider.h"
#include "TimeRigEventReference.h"
#include "StoryGraphTrigger_Event.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class TIMERIG_API UStoryGraphTrigger_Event : public UStoryGraphTriggerProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference SourceEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigEventReference TargetEvent;
    
    UStoryGraphTrigger_Event();
};

