#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NavAgent.h"
#include "NPC_MovementComponent.h"
#include "Enemy_MovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEnemy_MovementComponent : public UNPC_MovementComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavAgent NavAgent;
    
    UEnemy_MovementComponent();
    UFUNCTION(BlueprintCallable)
    void EnableDirectionLockModifier(FVector Direction);
    
    UFUNCTION(BlueprintCallable)
    void DisableDirectionLockModifier();
    
};

