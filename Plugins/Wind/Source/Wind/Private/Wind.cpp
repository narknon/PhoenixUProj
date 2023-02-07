#include "Wind.h"

class AActor;
class UObject;
class USceneComponent;

void UWind::WindWorldAzimuthToCompass(float WindAzimuthDegrees, EWindDirectionCompass& WindDirectionCompass) {
}

void UWind::WindDirectionToWorldAzimuthAltitude(UObject* WorldContextObject, FVector WindDirection, float& WindAzimuthDegrees, float& WindAltitudeDegrees) {
}

void UWind::WindDirectionToWorldAzimuth(UObject* WorldContextObject, FVector WindDirection, float& WindAzimuthDegrees) {
}

void UWind::WindDirectionToCompass(UObject* WorldContextObject, FVector WindDirection, EWindDirectionCompass& WindDirectionCompass) {
}

void UWind::WindDirectionCompassName(EWindDirectionCompass WindDirectionCompass, FString& CompassName) {
}

void UWind::GetWindAtPosition(UObject* WorldContextObject, FVector Position, FVector& WindDirection, float& WindSpeed, float IncludeOutdoors) {
}

void UWind::GetWindAtComponent(USceneComponent* SceneComponent, FVector& WindDirection, float& WindSpeed, bool& bIndoors) {
}

void UWind::GetWindAtActor(AActor* Actor, FVector& WindDirection, float& WindSpeed, bool& bIndoors) {
}

void UWind::BeaufortScaleName(EBeaufortWindScale BeaufortWindScale, int32& ScaleINdex, FString& ScaleName, FString& ScaleDescription) {
}

void UWind::BeaufortScaleFromSpeed(float WindSpeed, EBeaufortWindScale& BeaufortWindScale) {
}

UWind::UWind() {
}

