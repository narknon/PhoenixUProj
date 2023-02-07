#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ELightClippingPlanesFilterType.h"
#include "LightClippingPlanesSupportLibrary.generated.h"

class ALightClippingPlanes;
class ULevel;
class ULocalLightComponent;
class UObject;

UCLASS(Blueprintable)
class PHOENIX_API ULightClippingPlanesSupportLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULightClippingPlanesSupportLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLightClippingPlanesSource(ULocalLightComponent* LightComponent, ALightClippingPlanes*& LightClippingPlanesActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetAllWorldLightsWithTag(UObject* WorldContextObject, FName LightTag, TArray<ULocalLightComponent*>& Lights);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAllWithLightClippingPlanesActor(ALightClippingPlanes* LightClippingPlanesActor, TArray<ULocalLightComponent*>& Lights, ELightClippingPlanesFilterType FilterType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAllLevelLightsWithTag(ULevel* Level, FName LightTag, TArray<ULocalLightComponent*>& Lights);
    
    UFUNCTION(BlueprintCallable)
    static void FindAndAssignLightClippingPlanesSource(FName LightTag, ALightClippingPlanes* LightClippingPlanesActor, int32& AssignedLights, bool bForceEvenIfAlreadySet, bool bInvertClippingPlanes);
    
    UFUNCTION(BlueprintCallable)
    static void ClearLightClippingSource(ULocalLightComponent* LightComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllLightClippingPlanesSource(ALightClippingPlanes* LightClippingPlanesActor, int32& UnassignedLights);
    
    UFUNCTION(BlueprintCallable)
    static void AssignLightClippingPlanesSource(ULocalLightComponent* LightComponent, ALightClippingPlanes* LightClippingPlanesActor, bool& bSuccess, bool bInvertClippingPlanes);
    
};

