#include "TargetTypeDodgeDuck.h"

class UTargetTracker;
class UTargetTypeBase;

UTargetTypeBase* UTargetTypeDodgeDuck::AddTarget_DodgeDuck(UTargetTracker* TargetTracker, TEnumAsByte<ETargetID::Type> InTargetID, bool bUseCameraDirectionAlways) {
    return NULL;
}

UTargetTypeDodgeDuck::UTargetTypeDodgeDuck() {
    this->AngleOffset = 0.00f;
}

