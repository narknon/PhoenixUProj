#include "CameraStackSplineGetter.h"

class UCameraStack;
class USplineComponent;

void UCameraStackSplineGetter::Update(float DeltaSeconds) {
}

bool UCameraStackSplineGetter::IsValid() const {
    return false;
}

USplineComponent* UCameraStackSplineGetter::GetSpline() const {
    return NULL;
}

void UCameraStackSplineGetter::Activate(UCameraStack* InList) {
}

UCameraStackSplineGetter::UCameraStackSplineGetter() {
}

