#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESeasonEnum -FallbackName=ESeasonEnum
#include "EEventFrequency.h"
#include "EEventType.h"
#include "ESchedulerMoonPhase.h"
#include "ESchedulerTimeDateType.h"
#include "ESeasonEnum.h"
#include "EventDateTime.h"
#include "OnInitiateEndOfDayDelegate.h"
#include "OnStartNewDayDelegate.h"
#include "OnStartOfFirstDayDelegate.h"
#include "TimeEventDynamicDelegateDelegate.h"
#include "Scheduler.generated.h"

class UScheduler;

UCLASS(Blueprintable)
class GAMESCHEDULER_API UScheduler : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInitiateEndOfDay OnInitiateEndOfDay;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStartNewDay OnStartNewDay;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStartOfFirstDay OnStartOfFirstDay;
    
    UScheduler();
    UFUNCTION(BlueprintCallable)
    void StopTime(bool InStop, FName InLockName);
    
    UFUNCTION(BlueprintCallable)
    void StartNewDay();
    
    UFUNCTION(BlueprintCallable)
    void SetSimulationTimeFactorOverride(float Factor);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentTime(int32 InHours, int32 InMinutes, int32 InSeconds, int32 Month, int32 Day, int32 Year);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveRegisteredEvent(int32 InHandle, bool bInAssertIfNotFound);
    
    UFUNCTION(BlueprintCallable)
    int32 RegisterNewTimeEventBP(const FTimeEventDynamicDelegate& InSchedulerCallbackDelegate, TEnumAsByte<EEventType> InEventType, FEventDateTime InDate, TEnumAsByte<EEventFrequency> InEventFrequency);
    
    UFUNCTION(BlueprintCallable)
    void Pause(bool bInPause);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
    UFUNCTION(BlueprintCallable)
    static bool IsNowInBetweenStringTimes(const FString& StartTimeString, const FString& EndTimeString);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDay() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsClockStopped();
    
    UFUNCTION(BlueprintCallable)
    static void InitiateEndOfDay();
    
    UFUNCTION(BlueprintCallable)
    void Hide(bool bInHide);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalSeconds() const;
    
    UFUNCTION(BlueprintCallable)
    static int32 GetTimeDelta(int32 In24HourTimeA, int32 In24HourTimeB);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetStringTimeMinutes(const FString& TimeString);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSimulationTimeFactorOverride() const;
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSimulatedYearBP();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSimulatedTime24BP();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDateTime GetSimulatedTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSimulatedSecondMultiplier() const;
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSimulatedSecondBP();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSimulatedMonthBP();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSimulatedMinuteBP();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSimulatedHourBP();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSimulatedDayBP();
    
    UFUNCTION(BlueprintCallable)
    static FDateTime GetSimulateDateTimeBP();
    
    UFUNCTION(BlueprintCallable)
    static FString GetSimlatedTimeDateType(const TEnumAsByte<ESchedulerTimeDateType> InType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSecondOfTheDay() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDateTime GetNurtureTime() const;
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<ESchedulerMoonPhase> GetMoonPhaseBP();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMonthOfTheYear() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMinuteOfTheDay() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHourOfTheDay() const;
    
    UFUNCTION(BlueprintCallable)
    static void GetHourAndMinutesFromString(const FString& TimeString, int32& o_Hour, int32& o_Minute);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDayOfTheYear() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDayOfTheWeek() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDayOfTheMonth() const;
    
    UFUNCTION(BlueprintCallable)
    static ESeasonEnum GetCurrentSeason();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCalendarYear() const;
    
    UFUNCTION(BlueprintCallable)
    static bool GetActive();
    
    UFUNCTION(BlueprintCallable)
    static UScheduler* Get();
    
    UFUNCTION(BlueprintCallable)
    static void BeginFirstDay();
    
    UFUNCTION(BlueprintCallable)
    void AdvanceTimeTo(int32 InDays, int32 InHours, int32 InMinutes, int32 InSeconds);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceTime(int32 InDays, int32 InHours, int32 InMinutes, int32 InSeconds);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceSeconds(int32 InSeconds);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceNurtureTime(int32 InDays, int32 InHours, int32 InMinutes, int32 InSeconds);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceMinutes(int32 InMinutes);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceHours(int32 InHours);
    
    UFUNCTION(BlueprintCallable)
    void AdvanceDays(int32 InDays);
    
};

