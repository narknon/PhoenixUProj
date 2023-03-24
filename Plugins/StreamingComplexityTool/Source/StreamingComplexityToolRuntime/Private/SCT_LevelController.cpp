#include "SCT_LevelController.h"

ASCT_LevelController::ASCT_LevelController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseBlockingStreaming = false;
    this->bRunLevelMiners = false;
    this->bFlushAsyncThreadBeforeStreaming = false;
    this->bStreamLevelsIndependently = false;
    this->bUnloadLevelsPriorExit = false;
    this->bExitAtEnd = false;
    this->LevelToAnalyze = NULL;
}

