#include "ApparitionSpellTool.h"

void AApparitionSpellTool::TeleportNow() {
}

void AApparitionSpellTool::SetDirection(float X, float Y) {
}

AApparitionSpellTool::AApparitionSpellTool() {
    this->bShowDebug = false;
    this->ApparitionActorClass = NULL;
    this->TeleportFX = NULL;
    this->bUseBulletTime = false;
    this->BulletTimeRate = 0.10f;
    this->TimeDilationSfx = NULL;
    this->DistanceFromObstruction = 25.00f;
    this->SweepSphereRadius = 25.00f;
    this->SweepSegmentDistance = 100.00f;
    this->GroundSweepDistance = 500.00f;
    this->ApparitionActor = NULL;
}

