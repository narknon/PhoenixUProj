#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RequestedGoal.h"
#include "ScheduleEntry.h"
#include "ScheduledObject_Interface.generated.h"

class UStationComponent;

UINTERFACE(Blueprintable)
class UScheduledObject_Interface : public UInterface {
    GENERATED_BODY()
};

class IScheduledObject_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetMySubtype();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetMyName();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetMyID();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void GetCurrentActivity(bool& ActivityIsValid, FScheduleEntry& CurrentActivity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UStationComponent* GetActiveStation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetActiveGoal(FRequestedGoal& OutActiveGoal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetActiveActivity(FScheduleEntry& OutActiveActivity);
    
};

