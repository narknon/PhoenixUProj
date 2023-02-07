#include "OdcPathSpec.h"

FOdcPathSpec::FOdcPathSpec() {
    this->ObstacleMode = EOdcBlockageMode::BLOCKED_IF_ANY_MATCH;
    this->bUsePathSharingPenalty = false;
    this->PathSharingPenalty = 0.00f;
    this->MaxPathSharingPenalty = 0.00f;
    this->MaxSearchDist = 0.00f;
    this->SnapMode = EOdcSnapMode::SNAP_CLOSEST;
}

