#include "Scheduler.h"


void UScheduler::StopTime(bool InStop, FName InLockName) {
}

void UScheduler::StartNewDay() {
}

void UScheduler::SetSimulationTimeFactorOverride(float Factor) {
}

void UScheduler::SetCurrentTime(int32 InHours, int32 InMinutes, int32 InSeconds, int32 Month, int32 Day, int32 Year) {
}

bool UScheduler::RemoveRegisteredEvent(int32 InHandle, bool bInAssertIfNotFound) {
    return false;
}

int32 UScheduler::RegisterNewTimeEventBP(const FTimeEventDynamicDelegate& InSchedulerCallbackDelegate, TEnumAsByte<EEventType> InEventType, FEventDateTime InDate, TEnumAsByte<EEventFrequency> InEventFrequency) {
    return 0;
}

void UScheduler::Pause(bool bInPause) {
}

void UScheduler::OnSaveGameLoaded() {
}

void UScheduler::OnGameToBeSaved() {
}

bool UScheduler::IsNowInBetweenStringTimes(const FString& StartTimeString, const FString& EndTimeString) {
    return false;
}

bool UScheduler::IsNight() const {
    return false;
}

bool UScheduler::IsDay() const {
    return false;
}

bool UScheduler::IsClockStopped() {
    return false;
}

void UScheduler::InitiateEndOfDay() {
}

void UScheduler::Hide(bool bInHide) {
}

float UScheduler::GetTotalSeconds() const {
    return 0.0f;
}

int32 UScheduler::GetTimeDelta(int32 In24HourTimeA, int32 In24HourTimeB) {
    return 0;
}

int32 UScheduler::GetStringTimeMinutes(const FString& TimeString) {
    return 0;
}

float UScheduler::GetSimulationTimeFactorOverride() const {
    return 0.0f;
}

int32 UScheduler::GetSimulatedYearBP() {
    return 0;
}

int32 UScheduler::GetSimulatedTime24BP() {
    return 0;
}

FDateTime UScheduler::GetSimulatedTime() const {
    return FDateTime{};
}

float UScheduler::GetSimulatedSecondMultiplier() const {
    return 0.0f;
}

int32 UScheduler::GetSimulatedSecondBP() {
    return 0;
}

int32 UScheduler::GetSimulatedMonthBP() {
    return 0;
}

int32 UScheduler::GetSimulatedMinuteBP() {
    return 0;
}

int32 UScheduler::GetSimulatedHourBP() {
    return 0;
}

int32 UScheduler::GetSimulatedDayBP() {
    return 0;
}

FDateTime UScheduler::GetSimulateDateTimeBP() {
    return FDateTime{};
}

FString UScheduler::GetSimlatedTimeDateType(const TEnumAsByte<ESchedulerTimeDateType> InType) {
    return TEXT("");
}

int32 UScheduler::GetSecondOfTheDay() const {
    return 0;
}

FDateTime UScheduler::GetNurtureTime() const {
    return FDateTime{};
}

TEnumAsByte<ESchedulerMoonPhase> UScheduler::GetMoonPhaseBP() {
    return MOONPHASE_NEWMOON;
}

int32 UScheduler::GetMonthOfTheYear() const {
    return 0;
}

int32 UScheduler::GetMinuteOfTheDay() const {
    return 0;
}

int32 UScheduler::GetHourOfTheDay() const {
    return 0;
}

void UScheduler::GetHourAndMinutesFromString(const FString& TimeString, int32& o_Hour, int32& o_Minute) {
}

int32 UScheduler::GetDayOfTheYear() const {
    return 0;
}

int32 UScheduler::GetDayOfTheWeek() const {
    return 0;
}

int32 UScheduler::GetDayOfTheMonth() const {
    return 0;
}

ESeasonEnum UScheduler::GetCurrentSeason() {
    return ESeasonEnum::Season_Invalid;
}

int32 UScheduler::GetCalendarYear() const {
    return 0;
}

bool UScheduler::GetActive() {
    return false;
}

UScheduler* UScheduler::Get() {
    return NULL;
}

void UScheduler::BeginFirstDay() {
}

void UScheduler::AdvanceTimeTo(int32 InDays, int32 InHours, int32 InMinutes, int32 InSeconds) {
}

void UScheduler::AdvanceTime(int32 InDays, int32 InHours, int32 InMinutes, int32 InSeconds) {
}

void UScheduler::AdvanceSeconds(int32 InSeconds) {
}

void UScheduler::AdvanceNurtureTime(int32 InDays, int32 InHours, int32 InMinutes, int32 InSeconds) {
}

void UScheduler::AdvanceMinutes(int32 InMinutes) {
}

void UScheduler::AdvanceHours(int32 InHours) {
}

void UScheduler::AdvanceDays(int32 InDays) {
}

UScheduler::UScheduler() {
}

