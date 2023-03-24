#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "MountZoneVolumeBase.h"
#include "MountHeightLimitVolume.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable, HideDropdown, NotPlaceable)
class AMountHeightLimitVolume : public AMountZoneVolumeBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlyHeightOverride;
    
public:
    AMountHeightLimitVolume(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

