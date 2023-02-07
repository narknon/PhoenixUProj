#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "FlyingBroomPhysics.generated.h"

class UFlyingBroomMovementComponent;
class UFlyingBroomPhysicsScratch;

UCLASS(Blueprintable)
class UFlyingBroomPhysics : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugDraw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisablePhysics;
    
    UFlyingBroomPhysics();
    UFUNCTION(BlueprintCallable)
    void PhysicsUpdate(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void PhysicsRemoved(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch);
    
    UFUNCTION(BlueprintCallable)
    void PhysicsPostIteration(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch, const FVector& Adjusted, float timeTick);
    
    UFUNCTION(BlueprintCallable)
    FVector PhysicsIteration(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch, float timeTick);
    
    UFUNCTION(BlueprintCallable)
    void PhysicsAdded(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch);
    
    UFUNCTION(BlueprintCallable)
    UFlyingBroomPhysicsScratch* CreateScratch(UFlyingBroomMovementComponent* InOwner);
    
    UFUNCTION(BlueprintCallable)
    void AnimationUpdate(UFlyingBroomMovementComponent* FlyingBroomMovementComponent, UFlyingBroomPhysicsScratch* Scratch);
    
};

