#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "LightSmoothOnOff.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULightSmoothOnOff : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntensityChangeFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableIntensityFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TurnOnCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnOnDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve TurnOffCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnOffDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableOnOffSmoothing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TimeFactor;
    
    ULightSmoothOnOff();
    UFUNCTION(BlueprintCallable)
    void TurnOnOff(bool On, bool smooth);
    
    UFUNCTION(BlueprintCallable)
    void SetIntensity(float NewIntensity, bool Filter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnSmoothed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOn() const;
    
    UFUNCTION(BlueprintCallable)
    void Initialize(float Intensity, bool Visible);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSmoothedIntensity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetIntensity() const;
    
    UFUNCTION(BlueprintCallable)
    void AbortFadeOn(bool abortFade);
    
    UFUNCTION(BlueprintCallable)
    void AbortFadeOff(bool abortFade);
    
};

