#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MountZoneVolumeBase.h"
#include "NoDismountZoneVolume.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ANoDismountZoneVolume : public AMountZoneVolumeBase {
    GENERATED_BODY()
public:
    ANoDismountZoneVolume(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

