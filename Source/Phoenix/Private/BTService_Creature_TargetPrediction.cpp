#include "BTService_Creature_TargetPrediction.h"

UBTService_Creature_TargetPrediction::UBTService_Creature_TargetPrediction() {
    this->LookAheadTime = 2.00f;
    this->bUseParameterizedLookAheadTime = false;
    this->LookAheadOption = ECreatureTargetPredictionLookAheadOption::FromServiceActivation;
    this->TargetVelocityInterpSpeed = 10.00f;
    this->bCommit = true;
    this->CommitTime = 1.00f;
    this->bUseParameterizedCommitTime = false;
    this->bSetDesiredDirection = true;
    this->bClampToDistanceRange = false;
    this->bClampToHeadingRange = false;
    this->bClampToStraightLineReachableOnNavmesh = false;
    this->MaxStraightLineReachableAngleOffset = 30.00f;
    this->StraightLineReachableOption = ECreatureTargetPredictionStraightLineReachableOption::FromCurrentLocation;
    this->AttackData = NULL;
}

