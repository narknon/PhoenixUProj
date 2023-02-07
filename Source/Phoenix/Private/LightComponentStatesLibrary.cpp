#include "LightComponentStatesLibrary.h"

class AActor;
class UObject;

void ULightComponentStatesLibrary::LightComponentStatesUpdate(AActor* Actor, FLightComponentStatesSaveData& LightComponentStatesSaveData, bool bIncludeChildActors) {
}

void ULightComponentStatesLibrary::LightComponentStatesRestore(FLightComponentStatesSaveData& LightComponentStatesSaveData) {
}

void ULightComponentStatesLibrary::LightComponentStatesInitialize(UObject* Owner, FLightComponentStatesSaveData& LightComponentStatesSaveData, FLightComponentStates LightComponentStates) {
}

void ULightComponentStatesLibrary::AddLightComponentStateVisibility(UObject* Owner, FLightComponentStatesSaveData& LightComponentStatesSaveData, bool bVisible) {
}

void ULightComponentStatesLibrary::AddLightComponentStateCastShadow(UObject* Owner, FLightComponentStatesSaveData& LightComponentStatesSaveData, bool bCastShadow) {
}

ULightComponentStatesLibrary::ULightComponentStatesLibrary() {
}

