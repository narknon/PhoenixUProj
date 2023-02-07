#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightClusterComponentAuto.h"
#include "DayNightLightControllerComponent.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UDayNightLightControllerComponent : public UAnimatedLightClusterComponentAuto {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateThresholdDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeepScanChildren;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastSunAngleUpdate;
    
public:
    UDayNightLightControllerComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsLightControllerEnabled(bool& bIsControllerEnabled) const;
    
    UFUNCTION(BlueprintCallable)
    void EnableLightController(bool bEnableController);
    
};

