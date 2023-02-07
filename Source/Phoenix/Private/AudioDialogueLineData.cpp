#include "AudioDialogueLineData.h"

FAudioDialogueLineData::FAudioDialogueLineData() {
    this->DurationSeconds = 0.00f;
    this->DialogueHandle = 0;
    this->bIsFromConversation = false;
    this->bIsEmote = false;
    this->bForceSubtitle = false;
    this->bSuppressSubtitle = false;
    this->bSuppressSubtitleCharacterName = false;
    this->EmotionHint = EAvaAudioDialogueEmotionHint::DEH_None;
    this->SocialSemanticEmotionHint = SOCIAL_SEMANTIC_ALARM;
    this->AudioPriority = 0;
    this->bNonSpatialized = false;
}

