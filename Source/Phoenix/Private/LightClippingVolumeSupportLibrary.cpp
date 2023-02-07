#include "LightClippingVolumeSupportLibrary.h"

class ALightClippingVolume;
class ULocalLightComponent;

void ULightClippingVolumeSupportLibrary::GetLightClippingVolumeSource(ULocalLightComponent* LightComponent, ALightClippingVolume*& LightClippingVolumeActor) {
}

void ULightClippingVolumeSupportLibrary::GetAllWithLightClippingVolumeActor(ALightClippingVolume* LightClippingVolumeActor, TArray<ULocalLightComponent*>& Lights, ELightClippingVolumeFilterType FilterType) {
}

void ULightClippingVolumeSupportLibrary::FindAndAssignLightClippingVolumeSource(FName LightTag, ALightClippingVolume* LightClippingVolumeActor, int32& AssignedLights, bool bForceEvenIfAlreadySet, ELightClippingProviderVolumeMode VolumeMode) {
}

void ULightClippingVolumeSupportLibrary::ClearLightClippingSource(ULocalLightComponent* LightComponent) {
}

void ULightClippingVolumeSupportLibrary::ClearAllLightClippingVolumeSource(ALightClippingVolume* LightClippingVolumeActor, int32& UnassignedLights) {
}

void ULightClippingVolumeSupportLibrary::AssignLightClippingVolumeSource(ULocalLightComponent* LightComponent, ALightClippingVolume* LightClippingVolumeActor, bool& bSuccess, ELightClippingProviderVolumeMode VolumeMode) {
}

ULightClippingVolumeSupportLibrary::ULightClippingVolumeSupportLibrary() {
}

