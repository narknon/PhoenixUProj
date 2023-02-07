#include "WatcherRecord.h"

UWatcherRecord::UWatcherRecord() {
    this->bRequireControlReleaseBeforeActionPressed = false;
    this->bFilterMustBeTrueAtActionPressed = false;
    this->bFilterMustBeTrueAtActionReleased = false;
    this->bActionPressedMustHaveBeenSentToSendActionReleased = true;
    this->bRequireRepressAfterCancel = false;
    this->bExecuteWhenPaused = false;
    this->bModifierRequired = false;
    this->bRequiredModifierValue = false;
}

