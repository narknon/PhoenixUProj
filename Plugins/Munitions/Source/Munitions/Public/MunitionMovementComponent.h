#pragma once
#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MunitionMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MUNITIONS_API UMunitionMovementComponent : public UProjectileMovementComponent {
    GENERATED_BODY()
public:
    UMunitionMovementComponent();
};

