#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Mercuna3DMovementComponent.h"
#include "EBehaviorResult.h"
#include "Templates/SubclassOf.h"
#include "Icarus3DMovementComponent.generated.h"

class AActor;
class UAblAbility;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ICARUSRUNTIME_API UIcarus3DMovementComponent : public UMercuna3DMovementComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIcarusBehaviorComplete, const TEnumAsByte<EBehaviorResult::Type>, Result);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIcarusBehaviorComplete OnBehaviorCompleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanEverFly;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DefaultTakeOffAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> DefaultTakeOffAbilityOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartFlying;
    
public:
    UIcarus3DMovementComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTurningCircleRadius() const;
    
    UFUNCTION(BlueprintCallable)
    void EnableFlying();
    
    UFUNCTION(BlueprintCallable)
    void DisableFlying(bool bSwitchToGroundNavigation);
    
    UFUNCTION(BlueprintCallable)
    void BehaviorTakeOffStart(TSubclassOf<UAblAbility> TakeOffAbility, bool bTeleportIfNoTakeOffAbility);
    
    UFUNCTION(BlueprintCallable)
    void BehaviorStop(EBehaviorResult::Type Result);
    
    UFUNCTION(BlueprintCallable)
    void BehaviorLandingLocationStart(FVector LocationToLandAt, float Height);
    
    UFUNCTION(BlueprintCallable)
    void BehaviorLandingActorStart(AActor* ActorToLandAt, float Height, float ActorUpdateDistance);
    
    UFUNCTION(BlueprintCallable)
    void BehaviorCircleLocationStart(FVector CircleCenterLocation, float Radius, float Height, bool bClockwise, bool bLookAtCirclingLocation, float LookAtMaxPitch);
    
    UFUNCTION(BlueprintCallable)
    void BehaviorCircleActorStart(AActor* CircleCenterActor, float Radius, float Height, bool bClockwise, bool bLookAtCirclingActor, float LookAtMaxPitch, float ActorUpdateDistance);
    
};

