#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/StaticMeshComponent.h"
#include "FluidSimEmitterParams.h"
#include "FluidSimEmitterComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFluidSimEmitterComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FFluidSimEmitterParams EmitterParams;
    
    UFluidSimEmitterComponent();
    UFUNCTION(BlueprintCallable)
    void SetMotionVectorStrength(float MotionVectorStrengthIn);
    
    UFUNCTION(BlueprintCallable)
    void SetEmitterPos(const FVector4& EmitterPosIn);
    
    UFUNCTION(BlueprintCallable)
    void SetEmitterMultiplier(float EmitterMultiplierIn);
    
    UFUNCTION(BlueprintCallable)
    void SetEmitterDir(const FVector4& EmitterDirIn);
    
    UFUNCTION(BlueprintCallable)
    void SetEmitterBias(float EmitterBiasIn);
    
    UFUNCTION(BlueprintCallable)
    float GetMotionVectorStrength();
    
    UFUNCTION(BlueprintCallable)
    float GetEmitterMultiplier();
    
    UFUNCTION(BlueprintCallable)
    FVector4 GetEmitterDir();
    
    UFUNCTION(BlueprintCallable)
    float GetEmitterBias();
    
};

