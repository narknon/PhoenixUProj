#include "SceneAction_PlayForcedConversation.h"

USceneAction_PlayForcedConversation::USceneAction_PlayForcedConversation() {
    this->ConversationGraph = NULL;
    this->ConversationInitializationTime = EPlayForcedConversation_ConversationInitializationTime::WhenCreatingState;
}

