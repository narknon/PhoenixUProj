#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "PhysFallingCollisionDelegate.generated.h"

class UAmbulatory_MovementComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPhysFallingCollision, UAmbulatory_MovementComponent*, MoveComp, const FHitResult&, Hit);

