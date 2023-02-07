#include "AblBranchConditionDesiredDirectionDelta.h"

UAblBranchConditionDesiredDirectionDelta::UAblBranchConditionDesiredDirectionDelta() {
    this->UseSourceDirection = EDesiredDeltaSourceDirection::FacingDirection;
    this->UseTracker = EDesiredDeltaTargetTracker::DesiredDirection;
    this->BufferSampleTime = 0.00f;
    this->bAbsoulteValue = false;
    this->UseOperator = EDesiredDeltaOperator::And;
}

