#pragma once
#include "CoreMinimal.h"
#include "Able_MovementComponent.h"
#include "AvaAnimationMovementInterface.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "HermesBPDelegateHandle.h"
#include "Chaos/ChaosEngineInterface.h"
#include "AvaRootMotionWarper.h"
#include "HermesSurfaceTypeChangedDelegateDelegate.h"
#include "SharedContinuousImpulseHelper.h"
#include "Ambulatory_MovementComponent.generated.h"

class UAblAbilityComponent;
class UObject;
class USkeletalMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AMBULATORY_API UAmbulatory_MovementComponent : public UAble_MovementComponent, public IAvaAnimationMovementInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverridePhysWalking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bComputeDistanceToSurfaceWhenFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WindVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SuckHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowTransitionalImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalGravityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseNavMetricsForStepUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMitigateStuckFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMitigateStuckPenetratingExtraMovementCapsule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanEverStepOutOfWater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseWaterSurfaceForStepUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwimDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaterDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaterLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FluidFriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaterTerminalVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlowForceScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyMaxFlowForceLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFlowForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableSurfaceAcceleration;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvaRootMotionWarper AvaRootMotionWarper;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* AbleAbilityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator AnimRootMotionAngularVelocity;
    
public:
    UAmbulatory_MovementComponent();
    UFUNCTION(BlueprintCallable)
    void ZeroVelocity();
    
    UFUNCTION(BlueprintCallable)
    void ZeroLinearVelocity();
    
    UFUNCTION(BlueprintCallable)
    void UpdateSharedContinuousImpulse(FSharedContinuousImpulseHelper ImpulseContainer, const FVector& InImpulse, bool bInIgnoreMass);
    
    UFUNCTION(BlueprintCallable)
    FSharedContinuousImpulseHelper SetSharedContinuousLinearImpulse(const FVector& InImpulse);
    
    UFUNCTION(BlueprintCallable)
    void SetFrictionOverride(const float InFrictionOverride);
    
    UFUNCTION(BlueprintCallable)
    void SetFallImpulse(const FVector& Impulse);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowTransitionalImpulse(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    static void HermesBindSurfaceTypeChanged(FHermesSurfaceTypeChangedDelegate Delegate_SurfaceTypeChanged, const UObject* Owner, FHermesBPDelegateHandle& Handle);
    
    UFUNCTION(BlueprintCallable)
    float GetSurfaceIncline();
    
    UFUNCTION(BlueprintCallable)
    FVector GetFallLineFlat();
    
    UFUNCTION(BlueprintCallable)
    FVector GetFallLine();
    
    UFUNCTION(BlueprintCallable)
    float GetFallAlongSurfaceDistance();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EPhysicalSurface> GetCurrentSurfaceType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAdditiveToRootMotionVelocity() const;
    
    UFUNCTION(BlueprintCallable)
    FVector ComputeSurfaceAccelerationDirection(bool& bFlatGround);
    
    UFUNCTION(BlueprintCallable)
    void ClearTransitionalImpulse();
    
    UFUNCTION(BlueprintCallable)
    void ClearSharedContinuousImpulse(FSharedContinuousImpulseHelper ImpulseContainer);
    
    UFUNCTION(BlueprintCallable)
    void ClearLastSurfaceType();
    
    UFUNCTION(BlueprintCallable)
    void ClearAdditiveToRootMotionVelocity();
    
    UFUNCTION(BlueprintCallable)
    void AddToRootMotionVelocity(const FVector InAdditiveToRootMotionVelocity);
    
    
    // Fix for true pure virtual functions not being implemented
};

