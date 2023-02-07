#include "NewTutorialSequence.h"

FNewTutorialSequence::FNewTutorialSequence() {
    this->Persistence = ETutorialPersistence::Tutorial_Persistence_Restart;
    this->WaitForNotificationsToClear = false;
    this->MissionBannerNotification = false;
    this->LevelUpNotification = false;
    this->MissionStepNotification = false;
    this->OwlMailNotification = false;
    this->KnowledgeNotification = false;
    this->XPNotification = false;
    this->SpellNotification = false;
    this->ConversationActive = false;
    this->ShouldKeepCheckingForExitCondition = false;
    this->CanReplayTutorial = false;
}

