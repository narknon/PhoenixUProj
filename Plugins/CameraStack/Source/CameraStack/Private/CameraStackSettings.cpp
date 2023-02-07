#include "CameraStackSettings.h"

class UObject;

FCameraStackData UCameraStackSettings::GetStackData(const UObject* WorldContextObject) const {
    return FCameraStackData{};
}

UCameraStackSettings::UCameraStackSettings() {
}

