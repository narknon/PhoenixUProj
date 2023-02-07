#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ELightClippingProviderVolumeMode -FallbackName=ELightClippingProviderVolumeMode
#include "ELightClippingVolumeFilterType.h"
#include "LightClippingVolumeSupportLibrary.generated.h"

class ALightClippingVolume;
class ULocalLightComponent;

UCLASS(Blueprintable)
class PHOENIX_API ULightClippingVolumeSupportLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULightClippingVolumeSupportLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLightClippingVolumeSource(ULocalLightComponent* LightComponent, ALightClippingVolume*& LightClippingVolumeActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAllWithLightClippingVolumeActor(ALightClippingVolume* LightClippingVolumeActor, TArray<ULocalLightComponent*>& Lights, ELightClippingVolumeFilterType FilterType);
    
    UFUNCTION(BlueprintCallable)
    static void FindAndAssignLightClippingVolumeSource(FName LightTag, ALightClippingVolume* LightClippingVolumeActor, int32& AssignedLights, bool bForceEvenIfAlreadySet, ELightClippingProviderVolumeMode VolumeMode);
    
    UFUNCTION(BlueprintCallable)
    static void ClearLightClippingSource(ULocalLightComponent* LightComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllLightClippingVolumeSource(ALightClippingVolume* LightClippingVolumeActor, int32& UnassignedLights);
    
    UFUNCTION(BlueprintCallable)
    static void AssignLightClippingVolumeSource(ULocalLightComponent* LightComponent, ALightClippingVolume* LightClippingVolumeActor, bool& bSuccess, ELightClippingProviderVolumeMode VolumeMode);
    
};

