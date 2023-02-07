#include "TimeOverrideBlueprintLibrary.h"

class UObject;
class UTimeOverrideBase;

void UTimeOverrideBlueprintLibrary::RegisterTimeOverride(UObject* WorldContextObject, const UTimeOverrideBase* TimeOverride, bool& bSuccess) {
}

void UTimeOverrideBlueprintLibrary::IsTimeOverrideRegistered(UObject* WorldContextObject, const UTimeOverrideBase* TimeOverride, bool& bRegistered) {
}

void UTimeOverrideBlueprintLibrary::DeregisterTimeOverride(UObject* WorldContextObject, const UTimeOverrideBase* TimeOverride) {
}

UTimeOverrideBlueprintLibrary::UTimeOverrideBlueprintLibrary() {
}

