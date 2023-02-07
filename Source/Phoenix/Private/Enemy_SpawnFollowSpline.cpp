#include "Enemy_SpawnFollowSpline.h"

FEnemy_SpawnFollowSpline::FEnemy_SpawnFollowSpline() {
    this->SplinePtr = NULL;
    this->bUseLerpedSplineNormals = false;
    this->MinSpeed = 0.00f;
    this->MaxSpeed = 0.00f;
    this->MoveScale = 0.00f;
    this->Acceleration = 0.00f;
    this->Deceleration = 0.00f;
    this->speedRampDist = 0.00f;
    this->speedRampAccel = 0.00f;
    this->StartDirection = ENPC_FollowSplineDirection::Forward;
    this->Mobility = ENPC_Mobility::None;
    this->StartDist = 0.00f;
    this->StartSplineDelay = 0.00f;
    this->StartSplineDeviation = 0.00f;
    this->bWaitToStart = false;
    this->SplineInterval = 0.00f;
    this->SplineIntervalDeviation = 0.00f;
    this->SplineIdleChance = 0.00f;
    this->IdleMinInterval = 0.00f;
    this->ScurryState = ENPC_FollowSplineScurryState::Interval;
    this->ScurryProximityRadius = 0.00f;
    this->ScurryCheckInterval = 0.00f;
    this->ScurryCheckIntervalDeviation = 0.00f;
    this->ScurryChance = 0.00f;
    this->ScurryMinSpeed = 0.00f;
    this->ScurryMaxSpeed = 0.00f;
    this->ScurryInterval = 0.00f;
    this->ScurryIntervalDeviation = 0.00f;
    this->EndAction = ENPC_FollowSplineEndAction::None;
    this->bOnDieLeaveBehindBody = false;
    this->bAttemptAOEWhenReachingEnd = false;
    this->EndTimout = 0.00f;
    this->EndState = EEnemyAIState::None;
    this->bPerceptionEnabled = false;
    this->bOnPerceptionEndBypassAlert = false;
    this->bPerceptionEnabledOnNavMesh = false;
    this->bPerceptionEnableRequireDistance = false;
    this->PerceptionEnableMaxDistance = 0.00f;
    this->bOverrideShowUI = false;
    this->bTargetable = false;
    this->bPerceivable = false;
    this->bStealthKillable = false;
    this->bCollidable = false;
}

