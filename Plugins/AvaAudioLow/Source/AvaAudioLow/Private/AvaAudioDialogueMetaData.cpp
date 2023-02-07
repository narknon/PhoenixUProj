#include "AvaAudioDialogueMetaData.h"

FAvaAudioDialogueMetaData::FAvaAudioDialogueMetaData() {
    this->DurationSeconds = 0.00f;
    this->LipsyncPrerollSeconds = 0.00f;
    this->SocialSemanticEmotionHint = 0;
    this->EmotionHint = EAvaAudioDialogueEmotionHint::DEH_None;
    this->bIsLanguageSpecific = false;
    this->bIsEmote = false;
    this->bForceSubtitle = false;
    this->bSuppressSubtitle = false;
    this->bSuppressSubtitleCharacterName = false;
}

