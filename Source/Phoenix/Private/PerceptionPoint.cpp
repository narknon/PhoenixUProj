#include "PerceptionPoint.h"

class APerceptionPoint;
class APerceptionPointArea;

void APerceptionPoint::EnablePerception(bool bEnable, TArray<APerceptionPoint*> PerceptionPointList) {
}

void APerceptionPoint::Enable(bool bEnable) {
}

void APerceptionPoint::AttackDistanceScaleVolume(float InScale, TArray<APerceptionPointArea*> InAreaList) {
}

APerceptionPoint::APerceptionPoint() {
    this->bEnabled = true;
    this->bGameEventEnabled = false;
    this->Priority = 5;
    this->bTargetShareEnabled = true;
    this->bPlayerPP = false;
}

