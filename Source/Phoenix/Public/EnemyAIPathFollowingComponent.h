#pragma once
#include "CoreMinimal.h"
#include "NPC_PathFollowingComponent.h"
#include "EnemyAIPathFollowingComponent.generated.h"

class AAIController;
class APawn;
class UActorComponent;
class UCharacterMovementComponent;
class UEnemyAIComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemyAIPathFollowingComponent : public UNPC_PathFollowingComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APawn* PawnPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCharacterMovementComponent* CharacterMoveCompPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEnemyAIComponent* EnemyCompPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAIController* ControllerPtr;
    
public:
    UEnemyAIPathFollowingComponent();
    UFUNCTION(BlueprintCallable)
    void HandleComponentDeactivated(UActorComponent* InComponent);
    
    UFUNCTION(BlueprintCallable)
    void HandleComponentActivated(UActorComponent* InComponent, bool InSuccess);
    
};

