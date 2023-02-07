#include "LightClippingPlanesSupportLibrary.h"

class ALightClippingPlanes;
class ULevel;
class ULocalLightComponent;
class UObject;

void ULightClippingPlanesSupportLibrary::GetLightClippingPlanesSource(ULocalLightComponent* LightComponent, ALightClippingPlanes*& LightClippingPlanesActor) {
}

void ULightClippingPlanesSupportLibrary::GetAllWorldLightsWithTag(UObject* WorldContextObject, FName LightTag, TArray<ULocalLightComponent*>& Lights) {
}

void ULightClippingPlanesSupportLibrary::GetAllWithLightClippingPlanesActor(ALightClippingPlanes* LightClippingPlanesActor, TArray<ULocalLightComponent*>& Lights, ELightClippingPlanesFilterType FilterType) {
}

void ULightClippingPlanesSupportLibrary::GetAllLevelLightsWithTag(ULevel* Level, FName LightTag, TArray<ULocalLightComponent*>& Lights) {
}

void ULightClippingPlanesSupportLibrary::FindAndAssignLightClippingPlanesSource(FName LightTag, ALightClippingPlanes* LightClippingPlanesActor, int32& AssignedLights, bool bForceEvenIfAlreadySet, bool bInvertClippingPlanes) {
}

void ULightClippingPlanesSupportLibrary::ClearLightClippingSource(ULocalLightComponent* LightComponent) {
}

void ULightClippingPlanesSupportLibrary::ClearAllLightClippingPlanesSource(ALightClippingPlanes* LightClippingPlanesActor, int32& UnassignedLights) {
}

void ULightClippingPlanesSupportLibrary::AssignLightClippingPlanesSource(ULocalLightComponent* LightComponent, ALightClippingPlanes* LightClippingPlanesActor, bool& bSuccess, bool bInvertClippingPlanes) {
}

ULightClippingPlanesSupportLibrary::ULightClippingPlanesSupportLibrary() {
}

