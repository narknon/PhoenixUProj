#include "DayNightEVents.h"

class AActor;
class UActorComponent;
class UObject;

FTimespan UDayNightEVents::TimeInputAsTimespan(FTimeInput TimeInput) {
    return FTimespan{};
}

float UDayNightEVents::TimeInputAsFloat(FTimeInput TimeInput) {
    return 0.0f;
}

FTimespan UDayNightEVents::NormalizedTimeAsTimespan(const FSolarNormalizedTime& NormalizedTime) {
    return FTimespan{};
}

FString UDayNightEVents::NormalizedTimeAsString(const FSolarNormalizedTime& NormalizedTime) {
    return TEXT("");
}

float UDayNightEVents::NormalizedTimeAsFloat(const FSolarNormalizedTime& NormalizedTime) {
    return 0.0f;
}

FString UDayNightEVents::MoonPhaseAsString(const EMoonPhaseName& MoonPhase) {
    return TEXT("");
}

FName UDayNightEVents::MoonPhaseAsName(const EMoonPhaseName& MoonPhase) {
    return NAME_None;
}

bool UDayNightEVents::DayNightRemoveGlobalEvents(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName) {
    return false;
}

bool UDayNightEVents::DayNightRemoveComponentEvents(UActorComponent* Component, FName EventName) {
    return false;
}

bool UDayNightEVents::DayNightRemoveAllGlobalEvents(UObject* WorldContextObject, FName GlobalEventGroup) {
    return false;
}

bool UDayNightEVents::DayNightRemoveAllComponentEvents(UActorComponent* Component) {
    return false;
}

bool UDayNightEVents::DayNightRemoveAllActorEvents(AActor* Actor) {
    return false;
}

bool UDayNightEVents::DayNightRemoveActorEvents(AActor* Actor, FName EventName) {
    return false;
}

bool UDayNightEVents::DayNightGlobalRemoveComponentReceiver(UActorComponent* Component, FName GlobalEventGroup) {
    return false;
}

bool UDayNightEVents::DayNightGlobalRemoveAllReceivers(UObject* WorldContextObject, FName GlobalEventGroup) {
    return false;
}

bool UDayNightEVents::DayNightGlobalRemoveActorReceiver(AActor* Actor, FName GlobalEventGroup) {
    return false;
}

bool UDayNightEVents::DayNightGlobalAddComponentReceiver(UActorComponent* Component, FName GlobalEventGroup) {
    return false;
}

bool UDayNightEVents::DayNightGlobalAddActorReceiver(AActor* Actor, FName GlobalEventGroup) {
    return false;
}

void UDayNightEVents::DayNightGetGlobalSunsetEvent(FName& Event) {
}

void UDayNightEVents::DayNightGetGlobalSunriseSunsetEventGroup(FName& EventGroup) {
}

void UDayNightEVents::DayNightGetGlobalSunriseEvent(FName& Event) {
}

void UDayNightEVents::DayNightEventsLightsCanStartOn(UObject* WorldContextObject, bool& bLightsCanStartOn) {
}

void UDayNightEVents::DayNightEventsIsEditorWorld(UObject* WorldContextObject, bool& bIsEditorWorld) {
}

void UDayNightEVents::DayNightEventsCurrentState(UObject* WorldContextObject, FDayNightEventsCurrentState& CurrentState) {
}

bool UDayNightEVents::DayNightBeginPlayComponentEvents(UActorComponent* Component) {
    return false;
}

bool UDayNightEVents::DayNightBeginPlayActorEvents(AActor* Actor) {
    return false;
}

bool UDayNightEVents::DayNightAddGlobalTimeEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightNormalizedTimeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddGlobalSunEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightSunAltitudeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddGlobalSunChangeEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightSunAltitudeChangeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddGlobalMoonEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightMoonAltitudeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddGlobalGameTimeEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightGameTimeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddComponentTimeEvent(UActorComponent* Component, FName EventName, FDayNightNormalizedTimeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddComponentSunEvent(UActorComponent* Component, FName EventName, FDayNightSunAltitudeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddComponentSunChangeEvent(UActorComponent* Component, FName EventName, FDayNightSunAltitudeChangeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddComponentMoonEvent(UActorComponent* Component, FName EventName, FDayNightMoonAltitudeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddComponentGameTimeEvent(UActorComponent* Component, FName EventName, FDayNightGameTimeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddActorTimeEvent(AActor* Actor, FName EventName, FDayNightNormalizedTimeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddActorSunEvent(AActor* Actor, FName EventName, FDayNightSunAltitudeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddActorSunChangeEvent(AActor* Actor, FName EventName, FDayNightSunAltitudeChangeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddActorMoonEvent(AActor* Actor, FName EventName, FDayNightMoonAltitudeEvent DayNightEvent) {
    return false;
}

bool UDayNightEVents::DayNightAddActorGameTimeEvent(AActor* Actor, FName EventName, FDayNightGameTimeEvent DayNightEvent) {
    return false;
}

FDateTime UDayNightEVents::DateTimeInputAsDateTime(FDateTimeInput DateTimeInput, bool& Valid) {
    return FDateTime{};
}

UDayNightEVents::UDayNightEVents() {
}

