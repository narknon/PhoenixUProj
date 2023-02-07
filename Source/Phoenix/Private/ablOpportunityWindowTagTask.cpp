#include "ablOpportunityWindowTagTask.h"

UablOpportunityWindowTagTask::UablOpportunityWindowTagTask() {
    this->TagOperation = ETagOperation::Add;
    this->RemoveTagsAtEndOfTask = false;
    this->bCheckDatabaseId = false;
    this->bCheckSubtypeId = false;
}

