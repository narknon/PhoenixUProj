#include "RelativeTime.h"

FRelativeTime::FRelativeTime() {
    this->Offset = 0.00f;
    this->OffsetType = EOffsetTypeEnum::OFFSETTYPE_SECONDS;
    this->RelativeToType = ERelativeToEnum::RELATIVETO_START;
    this->RelativeToObject = NULL;
    this->bEditable = false;
}

