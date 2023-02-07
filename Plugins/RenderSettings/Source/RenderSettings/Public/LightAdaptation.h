#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DynamicLightAdaptationSettings.h"
#include "EmissiveAdaptationFinalState.h"
#include "LightAdaptation.generated.h"

class ULightAdaptationComponentChildOfLight;
class ULightComponent;
class UObject;

UCLASS(Blueprintable)
class RENDERSETTINGS_API ULightAdaptation : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULightAdaptation();
    UFUNCTION(BlueprintCallable)
    static void LightAdaptationSetIntensity(ULightComponent* LightComponent, float Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void LightAdaptationRegisterWithIntensity(ULightComponent* LightComponent, FDynamicLightAdaptationSettings Settings, float Intensity, ULightAdaptationComponentChildOfLight*& AdaptationComponent);
    
    UFUNCTION(BlueprintCallable)
    static void LightAdaptationRegister(ULightComponent* LightComponent, FDynamicLightAdaptationSettings Settings, ULightAdaptationComponentChildOfLight*& AdaptationComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LightAdaptationIntensityFactor(UObject* WorldContextObject, FDynamicLightAdaptationSettings Settings, float& IntensityFactor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void LightAdaptationGetIntensity(ULightComponent* LightComponent, float& Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void LightAdaptationDeregister(ULightAdaptationComponentChildOfLight* AdaptationComponent, bool bRestoreIntensity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetLightAdaptationState(UObject* WorldContextObject, FEmissiveAdaptationFinalState& State);
    
};

