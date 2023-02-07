#include "StoryGraphTrigger_Activate.h"

UStoryGraphTrigger_Activate::UStoryGraphTrigger_Activate() {
    this->InitializationType = EStoryGraphTriggerActive_InitializeType::InitializeWithPrevious;
    this->ActivationType = EStoryGraphTrigger_ActivateType::ActivatedByFinish;
    this->FeedbackType = ETimeRig_StoryGraphEdgeFeedbackType::NoFeedback;
}

