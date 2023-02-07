#pragma once
#include "CoreMinimal.h"
#include "VegetationInteractionComponent.h"
#include "VegetationInteractionSettings.h"
#include "VegetationInteractionSpringMassSettings.h"
#include "VegetationInteractionSpringMassTracker.h"
#include "VegetationInteractionVelocityTracker.h"
#include "VegetationInteractionComponentDualMode.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVegetationInteractionComponentDualMode : public UVegetationInteractionComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVegetationInteractionSettings SettingsMode0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVegetationInteractionSettings SettingsMode1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVegetationInteractionSpringMassSettings SpringMassMode0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVegetationInteractionSpringMassSettings SpringMassMode1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ModeTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ModeRate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVegetationInteractionVelocityTracker VelocityTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVegetationInteractionSpringMassTracker SpringMassTracker;
    
public:
    UVegetationInteractionComponentDualMode();
    UFUNCTION(BlueprintCallable)
    void SetVegetationInteractionModeSmooth(float TargetZeroOrOne, float RatePerSecond);
    
    UFUNCTION(BlueprintCallable)
    void SetVegetationInteractionModeImmediate(float TargetZeroOrOne);
    
};

