#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SkyStateOverrideBlueprintLibrary.generated.h"

class UObject;
class USkyStateOverride;

UCLASS(Blueprintable)
class DAYNIGHT_API USkyStateOverrideBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USkyStateOverrideBlueprintLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RegisterSkyStateOverride(UObject* WorldContextObject, const USkyStateOverride* SkyStateOverride, bool& bSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void IsSkyStateOverrideRegistered(UObject* WorldContextObject, const USkyStateOverride* SkyStateOverride, bool& bRegistered);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DeregisterSkyStateOverride(UObject* WorldContextObject, const USkyStateOverride* SkyStateOverride);
    
};

