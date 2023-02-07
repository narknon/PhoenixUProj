#include "Enemy_Turns_TicketUpdate_QBUpdateData.h"

UEnemy_Turns_TicketUpdate_QBUpdateData::UEnemy_Turns_TicketUpdate_QBUpdateData() {
    this->UpdateInterval = 0.10f;
    this->SinceLastAttackedCountCurve = NULL;
    this->OffScreenTimeCurve = NULL;
    this->RandomScoreMin = 0.10f;
    this->RandomScoreMax = 0.30f;
    this->RandomScoreTimeout = 5.00f;
    this->RandomScoreTimeoutDeviation = 1.00f;
    this->TargettedScore = 2.00f;
}

