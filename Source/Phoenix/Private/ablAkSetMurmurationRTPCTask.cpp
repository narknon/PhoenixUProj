#include "ablAkSetMurmurationRTPCTask.h"

UablAkSetMurmurationRTPCTask::UablAkSetMurmurationRTPCTask() {
    this->RTPC_Step = 0;
    this->bPlayerOnly = true;
    this->bDecay = true;
    this->RTPC_ValueType = EMurmurationValueType::Relative;
}

