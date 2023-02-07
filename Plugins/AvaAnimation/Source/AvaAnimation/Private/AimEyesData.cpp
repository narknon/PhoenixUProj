#include "AimEyesData.h"

UAimEyesData::UAimEyesData() {
    this->LookSmoothness = 0.60f;
    this->MinTimeForInitialCentralFocus = 4.00f;
    this->MaxTimeForInitialCentralFocus = 6.00f;
    this->MinTimeBetweenLookDir = 2.00f;
    this->MaxTimeBetweenLookDir = 3.00f;
    this->MinTimeBetweenBlinks = 4.00f;
    this->MaxTimeBetweenBlinks = 8.00f;
    this->DoubleBlinkProbability = 0.10f;
    this->PupilAxisOffset = 5.00f;
    this->MinTimeBetweenMicroLook = 0.20f;
    this->MaxTimeBetweenMicroLook = 0.50f;
    this->bUseRandomTargetIfNoCurrentTarget = true;
    this->MinRandomTargetTime = 5.00f;
    this->MaxRandomTargetTime = 12.00f;
    this->MaxYawRandomTarget = 4.00f;
    this->MaxPitchRandomTarget = 3.00f;
    this->MinRandomTargetDistance = 100.00f;
    this->MaxRandomTargetDistance = 500.00f;
    this->CentralFocusWeight = 0.50f;
    this->InternalMemoryWeight = 0.15f;
    this->AuditoryMemoryWeight = 0.05f;
    this->EmotionalMemoryWeight = 0.05f;
    this->VisualConstructionWeight = 0.05f;
    this->AuditoryConstructionWeight = 0.05f;
    this->BodySensationRecallWeight = 0.05f;
    this->SmellWeight = 0.05f;
    this->TasteWeight = 0.05f;
}

