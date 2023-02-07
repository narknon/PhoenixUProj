#include "FlyingBroomPhysics_FreeRoam.h"

UFlyingBroomPhysics_FreeRoam::UFlyingBroomPhysics_FreeRoam() {
    this->ThrusterEaseHalflife = 0.10f;
    this->ConformToGroundHeight = 200.00f;
    this->bUseWorldHeightForDangerZone = false;
    this->DangerZoneFromGround = 1000.00f;
    this->DangerZoneWorldHeight = 1000.00f;
    this->GroundBuffer = 100.00f;
    this->CeilingBuffer = 150.00f;
    this->ConformToGroundTime = 1.00f;
    this->bDangerZoneIfNoGroundFound = false;
    this->HoverYawMinInterpSpeed = 1.00f;
    this->HoverYawMaxInterpSpeed = 1.00f;
    this->PassiveYawMinInterpSpeed = 1.00f;
    this->PassiveYawMaxInterpSpeed = 1.00f;
    this->BoostYawMinInterpSpeed = 1.00f;
    this->BoostYawMaxInterpSpeed = 1.00f;
    this->TurboYawMinInterpSpeed = 1.00f;
    this->TurboYawMaxInterpSpeed = 1.00f;
    this->YawSpringHalfLife = 0.50f;
    this->MaxYawTurnAngle = 90.00f;
    this->WallTraceLengthMax = 500.00f;
    this->WallTraceVerticalLengthMax = 250.00f;
    this->WallTraceLengthStop = 1000.00f;
    this->VerticalImpulsePitch = 15.00f;
    this->PitchInterpSpeed = 5.00f;
    this->PitchSpringHalflife = 0.25f;
    this->DelayBeforeMoving = 0.00f;
    this->StartDirectionMatchTolerance = 0.00f;
    this->InterpToMaxSpeedSpeed = 1.00f;
    this->InterpToMaxSpeedType = ECustomInterpType::None;
    this->HoverMaxAnimTurn = 45.00f;
    this->PassiveMaxAnimTurn = 45.00f;
    this->BoostMaxAnimTurn = 45.00f;
    this->TurboMaxAnimTurn = 45.00f;
    this->HoverAnimTurnHalflife = 0.40f;
    this->FastAnimTurnHalflife = 0.25f;
    this->MaxAnimThrusterForce = 100.00f;
    this->AnimSpeedHalflife = 0.10f;
    this->AnimUpDownHalflife = 0.20f;
    this->ReactPushbackForceAmount = 200.00f;
}

