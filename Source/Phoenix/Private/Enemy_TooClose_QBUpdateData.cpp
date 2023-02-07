#include "Enemy_TooClose_QBUpdateData.h"

UEnemy_TooClose_QBUpdateData::UEnemy_TooClose_QBUpdateData() {
    this->TooCloseDist = 300.00f;
    this->TooCloseDistStop = 400.00f;
    this->bTeammateTooCloseCheck = true;
    this->TeammateTooCloseDist = 200.00f;
    this->TeammateTooCloseDistStop = 300.00f;
}

