#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MountHeightLimitComponent.generated.h"

class UMountRegionHeights;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMountHeightLimitComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMountRegionHeights* RegionHeights;
    
public:
    UMountHeightLimitComponent();
    UFUNCTION(BlueprintCallable)
    void SetHeightOverrides(float InTargetHeight, float InHeightBuffer);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFlyHeight() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearHeightOverrides();
    
};

