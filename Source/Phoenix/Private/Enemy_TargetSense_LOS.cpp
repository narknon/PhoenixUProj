#include "Enemy_TargetSense_LOS.h"

FEnemy_TargetSense_LOS::FEnemy_TargetSense_LOS() {
    this->LOSInterval = 0.00f;
    this->LOSMinDist = 0.00f;
    this->LOSUnawareInterval = 0.00f;
    this->LOSAwareInterval = 0.00f;
    this->LOSAlertInterval = 0.00f;
    this->LOSAggroInterval = 0.00f;
    this->LOSTeammateInterval = 0.00f;
}

