#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TimeOverrideBlueprintLibrary.generated.h"

class UObject;
class UTimeOverrideBase;

UCLASS(Blueprintable)
class DAYNIGHT_API UTimeOverrideBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTimeOverrideBlueprintLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RegisterTimeOverride(UObject* WorldContextObject, const UTimeOverrideBase* TimeOverride, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsTimeOverrideRegistered(UObject* WorldContextObject, const UTimeOverrideBase* TimeOverride, bool& bRegistered);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DeregisterTimeOverride(UObject* WorldContextObject, const UTimeOverrideBase* TimeOverride);
    
};

