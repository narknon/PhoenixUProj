#include "ablNPC_SplitTask.h"

UablNPC_SplitTask::UablNPC_SplitTask() {
    this->SplitMode = ENPC_Split::None;
    this->bIgnoreSelectRanges = false;
    this->bIgnoreMinAttackAngle = false;
    this->bGetSplitFromCurrentAttackData = false;
}

