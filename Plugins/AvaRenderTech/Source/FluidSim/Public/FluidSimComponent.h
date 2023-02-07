#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "FluidSimParams.h"
#include "FluidSimComponent.generated.h"

class UCurveLinearColor;
class UTexture2D;

UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFluidSimComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FFluidSimParams FluidSimParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ColorMap;
    
    UFluidSimComponent();
    UFUNCTION(BlueprintCallable)
    void SetVorticityTrails(float VorticityTrailsIn);
    
    UFUNCTION(BlueprintCallable)
    void SetVorticity(float VorticityIn);
    
    UFUNCTION(BlueprintCallable)
    void SetVolumeScale(FVector VolumeScaleIn);
    
    UFUNCTION(BlueprintCallable)
    void SetVolumeMotion(bool VolumeMotionIn);
    
    UFUNCTION(BlueprintCallable)
    void SetVelocityDissipation(float VelocityDissipationIn);
    
    UFUNCTION(BlueprintCallable)
    void SetTimeStep(float TimeStepIn);
    
    UFUNCTION(BlueprintCallable)
    void SetSourceDissipation(float SourceDissipationIn);
    
    UFUNCTION(BlueprintCallable)
    void SetMotionVectorStrength(float MotionVectorStrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void SetFadeEdges(bool FadeEdgesIn);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool EnabledIn);
    
    UFUNCTION(BlueprintCallable)
    void SetDrawDebugBounds(bool DrawDebugBoundsIn);
    
    UFUNCTION(BlueprintCallable)
    void SetDensity(float DensityIn);
    
    UFUNCTION(BlueprintCallable)
    void SetComputeDimensions(FVector ComputeDimensionsIn);
    
    UFUNCTION(BlueprintCallable)
    void SetColorIntensity(float ColorIntensityIn);
    
    UFUNCTION(BlueprintCallable)
    void SetColorCurveScale(float ColorCurveScaleIn);
    
    UFUNCTION(BlueprintCallable)
    void SetColorCurve(UCurveLinearColor* ColorCurveIn);
    
    UFUNCTION(BlueprintCallable)
    void SetBuoyancyGravity(FVector BuoyancyGravityIn);
    
    UFUNCTION(BlueprintCallable)
    float GetVorticityTrails();
    
    UFUNCTION(BlueprintCallable)
    float GetVorticity();
    
    UFUNCTION(BlueprintCallable)
    FVector GetVolumeScale();
    
    UFUNCTION(BlueprintCallable)
    bool GetVolumeMotion();
    
    UFUNCTION(BlueprintCallable)
    float GetVelocityDissipation();
    
    UFUNCTION(BlueprintCallable)
    float GetTimeStep();
    
    UFUNCTION(BlueprintCallable)
    float GetMotionVectorStrength();
    
    UFUNCTION(BlueprintCallable)
    bool GetFadeEdges();
    
    UFUNCTION(BlueprintCallable)
    bool GetEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool GetDrawDebugBounds();
    
    UFUNCTION(BlueprintCallable)
    float GetDensity();
    
    UFUNCTION(BlueprintCallable)
    FVector GetComputeDimensions();
    
    UFUNCTION(BlueprintCallable)
    float GetColorIntensity();
    
    UFUNCTION(BlueprintCallable)
    float GetColorCurveScale();
    
    UFUNCTION(BlueprintCallable)
    UCurveLinearColor* GetColorCurve();
    
    UFUNCTION(BlueprintCallable)
    FVector GetBuoyancyGravity();
    
};

