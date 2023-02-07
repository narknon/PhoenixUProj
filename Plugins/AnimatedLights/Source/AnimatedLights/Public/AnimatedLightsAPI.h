#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AnimatedLightsAPI.generated.h"

class ULightComponent;

UCLASS(Blueprintable)
class ANIMATEDLIGHTS_API UAnimatedLightsAPI : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAnimatedLightsAPI();
    UFUNCTION(BlueprintCallable)
    static bool SetAnimatedLightIntensity(ULightComponent* Light, float Intensity, bool bSetEvenIfNotAnimated);
    
    UFUNCTION(BlueprintCallable)
    static bool SetAnimatedLightColorIntensity(ULightComponent* Light, FLinearColor Color, float Intensity, bool bSetEvenIfNotAnimated);
    
    UFUNCTION(BlueprintCallable)
    static bool SetAnimatedLightColor(ULightComponent* Light, FLinearColor Color, bool bSetEvenIfNotAnimated);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsAnimatedLight(ULightComponent* Light, bool& bIsAnimatedLight);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAnimatedLightIntensity(ULightComponent* Light, float& Intensity, bool bGetEvenIfNotAnimated);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAnimatedLightColorIntensity(ULightComponent* Light, FLinearColor& Color, float& Intensity, bool bGetEvenIfNotAnimated);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAnimatedLightColor(ULightComponent* Light, FLinearColor& Color, bool bGetEvenIfNotAnimated);
    
};

