#include "StoryGraphTrigger_Initialize.h"

UStoryGraphTrigger_Initialize::UStoryGraphTrigger_Initialize() {
    this->InitializationType = EStoryGraphTrigger_InitializeType::InitializeWithPrevious;
    this->FeedbackType = ETimeRig_StoryGraphEdgeFeedbackType::NoFeedback;
}

