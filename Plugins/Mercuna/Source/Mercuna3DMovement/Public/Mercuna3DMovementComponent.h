#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Mercuna3DMovementInterface.h"
#include "Mercuna3DMovementProperties.h"
#include "Mercuna3DMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MERCUNA3DMOVEMENT_API UMercuna3DMovementComponent : public UPawnMovementComponent, public IMercuna3DMovementInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercuna3DMovementProperties MovementProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bPositionCorrected: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PendingImpulseToApply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector Acceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector AngularVelocity;
    
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSimulationTimeStep;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSimulationIterations;
    
    UMercuna3DMovementComponent();
    UFUNCTION(BlueprintCallable)
    void SetVelocity(FVector NewVelocity);
    
    UFUNCTION(BlueprintCallable)
    void SetAngularVelocity(FVector NewAngVel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetLocalVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetLocalRotationRate() const;
    
    UFUNCTION(BlueprintCallable)
    void AddImpulse(FVector Impulse);
    
    
    // Fix for true pure virtual functions not being implemented
};

