#include "StoryGraph_Conversation.h"

UStoryGraph_Conversation::UStoryGraph_Conversation() {
    this->ArticyImport = EConversationImport::ImportFromArticy;
    this->AmbientSceneRig = NULL;
    this->DefaultConversationSR = NULL;
    this->bEnableInitialFadeOut = true;
    this->bEnableInitialFadeIn = true;
    this->bEnableFinalFadeOut = true;
    this->bEnableFinalFadeIn = true;
    this->ConversationPreset = NULL;
    this->NpcStart = NULL;
    this->PlayerFinish = NULL;
    this->bEnableImpliedFacialEmotions = false;
    this->SynchronizationMethod = ESynchronizeMethod::Synchronize_Schedule;
    this->bEnableLightRig = true;
    this->bUsesSkyColors = true;
    this->KeyLightColorTemperature = 6500.00f;
    this->RimLightColorTemperature = 6500.00f;
    this->FillLightColorTemperature = 6500.00f;
    this->KeyLightIntensity = 0.40f;
    this->RimLightIntensity = 1.30f;
    this->FillLightIntensity = 1.50f;
    this->LastBuiltEventHash = 0;
    this->RebuildEdStoryGraph = false;
}

