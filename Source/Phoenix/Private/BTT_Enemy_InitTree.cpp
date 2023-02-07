#include "BTT_Enemy_InitTree.h"

UBTT_Enemy_InitTree::UBTT_Enemy_InitTree() {
    this->bForceEntry = false;
    this->Timeout = 0.00f;
    this->TimeoutAction = EEnemy_InitTreeTimeoutAction::FailNoEnter;
    this->AbortMove = true;
}

