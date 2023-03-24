#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "WaterMill_Gears.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class PHOENIX_API AWaterMill_Gears : public AActor {
    GENERATED_BODY()
public:
    AWaterMill_Gears(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateWaterWheelMaterialValues();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetSpeedControl();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetRotationRates(TArray<FVector>& Array);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetGearComponents(TArray<UStaticMeshComponent*>& Array);
    
};

