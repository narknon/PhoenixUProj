#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "DayNightTimeOverrideInterface.h"
#include "TimeOverrideBase.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class DAYNIGHT_API UTimeOverrideBase : public UObject, public IDayNightTimeOverrideInterface {
    GENERATED_BODY()
public:
    UTimeOverrideBase();
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void TimeOverrideSetTime(FTimespan Time, bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void TimeOverrideSetNormalizedTime(float Time, bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void TimeOverrideSetEnable(bool bEnable, bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void TimeOverrideSetDateTime(FDateTime DateTime, bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideIsEnabled(bool& bEnabled) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideHasTime(bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideHasNormalizedTime(bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideHasDateTime(bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideGetTime(FTimespan& CurrentTime, bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideGetPriority(float& Priority) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideGetNormalizedTime(float& CurrentNormalizedTime, bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideGetDateTime(FDateTime& CurrentDateTime, bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideCanSetTime(bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideCanSetNormalizedTime(bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideCanSetEnable(bool& bSupported) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void TimeOverrideCanSetDateTime(bool& bSupported) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

