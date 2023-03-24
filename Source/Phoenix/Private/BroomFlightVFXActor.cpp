#include "BroomFlightVFXActor.h"













ABroomFlightVFXActor::ABroomFlightVFXActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MapTraceType = TraceTypeQuery1;
    this->Time = 0.00f;
    this->PitchMultiply = 0.00f;
    this->YawMultiply = 0.00f;
    this->YawStrength = 0.00f;
    this->SpawnedSystem = NULL;
    this->DynamicBroomMaterial = NULL;
    this->BroomPostProcess = NULL;
    this->BroomNiagara = NULL;
}

