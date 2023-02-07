#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EBeaufortWindScale.h"
#include "EWindDirectionCompass.h"
#include "Wind.generated.h"

class AActor;
class UObject;
class USceneComponent;

UCLASS(Blueprintable)
class WIND_API UWind : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UWind();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void WindWorldAzimuthToCompass(float WindAzimuthDegrees, EWindDirectionCompass& WindDirectionCompass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void WindDirectionToWorldAzimuthAltitude(UObject* WorldContextObject, FVector WindDirection, float& WindAzimuthDegrees, float& WindAltitudeDegrees);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void WindDirectionToWorldAzimuth(UObject* WorldContextObject, FVector WindDirection, float& WindAzimuthDegrees);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void WindDirectionToCompass(UObject* WorldContextObject, FVector WindDirection, EWindDirectionCompass& WindDirectionCompass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void WindDirectionCompassName(EWindDirectionCompass WindDirectionCompass, FString& CompassName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetWindAtPosition(UObject* WorldContextObject, FVector Position, FVector& WindDirection, float& WindSpeed, float IncludeOutdoors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetWindAtComponent(USceneComponent* SceneComponent, FVector& WindDirection, float& WindSpeed, bool& bIndoors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetWindAtActor(AActor* Actor, FVector& WindDirection, float& WindSpeed, bool& bIndoors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void BeaufortScaleName(EBeaufortWindScale BeaufortWindScale, int32& ScaleINdex, FString& ScaleName, FString& ScaleDescription);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void BeaufortScaleFromSpeed(float WindSpeed, EBeaufortWindScale& BeaufortWindScale);
    
};

