#include "MissionLogData.h"

FMissionLogData::FMissionLogData() {
    this->MissionLevel = 0;
    this->SuggestedMissionLevel = 0;
    this->MissionLine = EMissionLine::Main;
    this->IsSpine = false;
    this->IsHomework = false;
    this->IsRelationship = false;
    this->IsExclusive = false;
    this->IsTrackable = false;
    this->IsComplete = false;
}

