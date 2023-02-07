#include "TargetTypeCognitionTarget.h"

class AActor;
class UTargetTracker;
class UTargetTypeBase;

UTargetTypeBase* UTargetTypeCognitionTarget::AddTarget_CognitionTarget(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID, AActor* InTargetActor, UClass* InSense, bool NewBLookAt) {
    return NULL;
}

UTargetTypeCognitionTarget::UTargetTypeCognitionTarget() {
    this->Sense = NULL;
    this->bLookAt = true;
}

