#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EmissiveAdaptationFinalState.h"
#include "EmissiveAdaptationBlueprintLibrary.generated.h"

class UObject;

UCLASS(Blueprintable)
class RENDERSETTINGS_API UEmissiveAdaptationBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UEmissiveAdaptationBlueprintLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void UnrealToEV100(float UnrealExposure, float& EV100Exposure);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEmissiveAdaptationState(UObject* WorldContextObject, FEmissiveAdaptationFinalState& State);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEmissiveAdaptationOutdoorsDayTime(UObject* WorldContextObject, float& OutdoorsDayTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEmissiveAdaptationMinMaxExposureEV100(UObject* WorldContextObject, float& MinExposureEV100, float& MaxExposureEV100, float& BiasPow2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEmissiveAdaptationMinMaxExposure(UObject* WorldContextObject, float& MinExposure, float& MaxExposure, float& Bias);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEmissiveAdaptationFinalMultiplierClamped(UObject* WorldContextObject, float& FinalMultiplierClamped);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetEmissiveAdaptationFinalMultiplier(UObject* WorldContextObject, float& FinalMultiplier, float& FactorMin, float& FactorMax);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void EV100ToUnreal(float EV100Exposure, float& UnrealExposure);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void BiasFactorToEV100(float Factor, float& EV00Bias);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void BiasFactor(float EV00Bias, float& Factor);
    
};

