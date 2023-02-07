#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblChangeCollisionCapsuleDimensions.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblChangeCollisionCapsuleDimensions : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollisionCapsuleHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CollisionCapsuleRadius;
    
public:
    UAblChangeCollisionCapsuleDimensions();
};

