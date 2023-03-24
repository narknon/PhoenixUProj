#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "EBroomEnemyState.h"
#include "EnemyBroomRider_AiController.generated.h"

class ACharacter;
class UFlyingBroomPhysics;
class UFlyingBroomPhysicsScratch_Spline;
class UScheduledEntity;

UCLASS(Blueprintable)
class AEnemyBroomRider_AiController : public AController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFlyingBroomPhysics* BroomPhysics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EBroomEnemyState::Type> BroomEnemyState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OverrideYaw;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UScheduledEntity* OwnedScheduledEntity;
    
public:
    AEnemyBroomRider_AiController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopAndWaitForPlayer(float CriticalDistance);
    
    UFUNCTION(BlueprintCallable)
    void SetBroomYaw(float Yaw);
    
    UFUNCTION(BlueprintCallable)
    void ResumeBroom();
    
    UFUNCTION(BlueprintCallable)
    void PauseBroom();
    
    UFUNCTION(BlueprintCallable)
    void GoToPointOnSpline(int32 Point);
    
    UFUNCTION(BlueprintCallable)
    float GetDistanceFromPlayer(UFlyingBroomPhysicsScratch_Spline* SplinePhysicsScratch, ACharacter* Player);
    
    UFUNCTION(BlueprintCallable)
    void BarrelRollRight();
    
    UFUNCTION(BlueprintCallable)
    void BarrelRollLeft();
    
};

