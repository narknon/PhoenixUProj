#include "ShadowSprintData.h"

UShadowSprintData::UShadowSprintData() {
    this->ConformToGroundHeight = 200.00f;
    this->DangerZone = 1000.00f;
    this->GroundBuffer = 100.00f;
    this->CeilingBuffer = 150.00f;
    this->ConformToGroundTime = 1.00f;
    this->bDangerZoneIfNoGroundFound = false;
    this->YawMinInterpSpeed = 5.00f;
    this->YawMaxInterpSpeed = 5.00f;
    this->PitchInterpSpeed = 5.00f;
    this->PitchBackToZeroInterpSpeed = 5.00f;
    this->bDebugDraw = false;
    this->bDisablePhysics = false;
}

