#include "SceneAction_ConversationLightRigOptions.h"

USceneAction_ConversationLightRigOptions::USceneAction_ConversationLightRigOptions() {
    this->GetFromConversation = true;
    this->bKeepStateOnCompletion = false;
    this->bUsesSkyColors = true;
    this->KeyLightColorTemperature = 6500.00f;
    this->RimLightColorTemperature = 6500.00f;
    this->FillLightColorTemperature = 6500.00f;
    this->KeyLightIntensity = 0.40f;
    this->RimLightIntensity = 1.30f;
    this->FillLightIntensity = 1.50f;
}

