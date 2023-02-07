#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DateTimeInput.h"
#include "DayNightEventsCurrentState.h"
#include "DayNightGameTimeEvent.h"
#include "DayNightMoonAltitudeEvent.h"
#include "DayNightNormalizedTimeEvent.h"
#include "DayNightSunAltitudeChangeEvent.h"
#include "DayNightSunAltitudeEvent.h"
#include "EMoonPhaseName.h"
#include "SolarNormalizedTime.h"
#include "TimeInput.h"
#include "DayNightEVents.generated.h"

class AActor;
class UActorComponent;
class UObject;

UCLASS(Blueprintable)
class DAYNIGHT_API UDayNightEVents : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UDayNightEVents();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTimespan TimeInputAsTimespan(FTimeInput TimeInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float TimeInputAsFloat(FTimeInput TimeInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTimespan NormalizedTimeAsTimespan(const FSolarNormalizedTime& NormalizedTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString NormalizedTimeAsString(const FSolarNormalizedTime& NormalizedTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float NormalizedTimeAsFloat(const FSolarNormalizedTime& NormalizedTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString MoonPhaseAsString(const EMoonPhaseName& MoonPhase);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName MoonPhaseAsName(const EMoonPhaseName& MoonPhase);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightRemoveGlobalEvents(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightRemoveComponentEvents(UActorComponent* Component, FName EventName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightRemoveAllGlobalEvents(UObject* WorldContextObject, FName GlobalEventGroup);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightRemoveAllComponentEvents(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightRemoveAllActorEvents(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightRemoveActorEvents(AActor* Actor, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightGlobalRemoveComponentReceiver(UActorComponent* Component, FName GlobalEventGroup);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightGlobalRemoveAllReceivers(UObject* WorldContextObject, FName GlobalEventGroup);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightGlobalRemoveActorReceiver(AActor* Actor, FName GlobalEventGroup);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightGlobalAddComponentReceiver(UActorComponent* Component, FName GlobalEventGroup);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightGlobalAddActorReceiver(AActor* Actor, FName GlobalEventGroup);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void DayNightGetGlobalSunsetEvent(FName& Event);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void DayNightGetGlobalSunriseSunsetEventGroup(FName& EventGroup);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void DayNightGetGlobalSunriseEvent(FName& Event);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightEventsLightsCanStartOn(UObject* WorldContextObject, bool& bLightsCanStartOn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightEventsIsEditorWorld(UObject* WorldContextObject, bool& bIsEditorWorld);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightEventsCurrentState(UObject* WorldContextObject, FDayNightEventsCurrentState& CurrentState);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightBeginPlayComponentEvents(UActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightBeginPlayActorEvents(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightAddGlobalTimeEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightNormalizedTimeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightAddGlobalSunEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightSunAltitudeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightAddGlobalSunChangeEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightSunAltitudeChangeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightAddGlobalMoonEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightMoonAltitudeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool DayNightAddGlobalGameTimeEvent(UObject* WorldContextObject, FName GlobalEventGroup, FName EventName, FDayNightGameTimeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddComponentTimeEvent(UActorComponent* Component, FName EventName, FDayNightNormalizedTimeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddComponentSunEvent(UActorComponent* Component, FName EventName, FDayNightSunAltitudeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddComponentSunChangeEvent(UActorComponent* Component, FName EventName, FDayNightSunAltitudeChangeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddComponentMoonEvent(UActorComponent* Component, FName EventName, FDayNightMoonAltitudeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddComponentGameTimeEvent(UActorComponent* Component, FName EventName, FDayNightGameTimeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddActorTimeEvent(AActor* Actor, FName EventName, FDayNightNormalizedTimeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddActorSunEvent(AActor* Actor, FName EventName, FDayNightSunAltitudeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddActorSunChangeEvent(AActor* Actor, FName EventName, FDayNightSunAltitudeChangeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddActorMoonEvent(AActor* Actor, FName EventName, FDayNightMoonAltitudeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable)
    static bool DayNightAddActorGameTimeEvent(AActor* Actor, FName EventName, FDayNightGameTimeEvent DayNightEvent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDateTime DateTimeInputAsDateTime(FDateTimeInput DateTimeInput, bool& Valid);
    
};

