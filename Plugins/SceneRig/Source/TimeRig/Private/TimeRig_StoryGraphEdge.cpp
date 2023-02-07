#include "TimeRig_StoryGraphEdge.h"

UTimeRig_StoryGraphEdge::UTimeRig_StoryGraphEdge() {
    this->Condition = NULL;
    this->Trigger = NULL;
    this->InitializationType = ETimeRig_StoryGraphEdgeInitType::InitializeWhenTriggered;
    this->TriggerType = ETimeRig_StoryGraphEdgeTriggerType::TriggeredByFinish;
    this->FeedbackType = ETimeRig_StoryGraphEdgeFeedbackType::NoFeedback;
    this->StartNode = NULL;
    this->EndNode = NULL;
}

