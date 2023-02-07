#include "DayNightMasterComponent.h"

class UDayNightMasterComponent;
class UObject;

bool UDayNightMasterComponent::GetPointOfInterest(UObject* WorldContextObject, FName Name, FCelestialPointOfInterest& poi) {
    return false;
}

void UDayNightMasterComponent::GetNightZeroToOne(UObject* WorldContextObject, float& DayNightValue) {
}

void UDayNightMasterComponent::GetNightZeroDayOne(UObject* WorldContextObject, float& DayNightValue) {
}

void UDayNightMasterComponent::GetNightNegOneDayOne(UObject* WorldContextObject, float& DayNightValue) {
}

void UDayNightMasterComponent::GetDayZeroToOne(UObject* WorldContextObject, float& DayNightValue) {
}

void UDayNightMasterComponent::GetDayNightMaster(UObject* WorldContextObject, UDayNightMasterComponent*& DayNightMaster) {
}

void UDayNightMasterComponent::DayNightGetNormalizedTime(UObject* WorldContextObject, FSolarNormalizedTime& CurrentTime, bool& Valid) {
}

void UDayNightMasterComponent::DayNightGetNightZeroToOne(UObject* WorldContextObject, float& DayNightValue) {
}

void UDayNightMasterComponent::DayNightGetNightZeroDayOne(UObject* WorldContextObject, float& DayNightValue) {
}

void UDayNightMasterComponent::DayNightGetNightNegOneDayOne(UObject* WorldContextObject, float& DayNightValue) {
}

void UDayNightMasterComponent::DayNightGetDayZeroToOne(UObject* WorldContextObject, float& DayNightValue) {
}

UDayNightMasterComponent::UDayNightMasterComponent() {
    this->ForceWorldBasis = NULL;
    this->SkyActorOverride = NULL;
    this->DebugOrbits = NULL;
    this->LastNormalizedTime = -1.00f;
}

