#include "AblSetCharacterTagsTask.h"

UAblSetCharacterTagsTask::UAblSetCharacterTagsTask() {
    this->RemoveTagsAtEndOfTask = false;
    this->AddTheseTags = false;
    this->RemoveTheseTags = false;
    this->bMustPassAllConditions = false;
}

