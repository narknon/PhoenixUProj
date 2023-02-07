#include "DynamicObjectLoadInfo.h"

FDynamicObjectLoadInfo::FDynamicObjectLoadInfo() {
    this->bIsPersistent = false;
    this->bFindValidPostion = false;
    this->bIsQuestRelevant = false;
    this->SearchRadius = 0.00f;
    this->ParentID = 0;
    this->ObjectID = 0;
}

