#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WaterInteractionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FLOW_API UWaterInteractionComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanRipple;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> BonesToTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntensityMultiplier;
    
public:
    UWaterInteractionComponent();
    UFUNCTION(BlueprintCallable)
    void WakeUp(bool bEnableForWater);
    
    UFUNCTION(BlueprintCallable)
    void Sleep();
    
};

