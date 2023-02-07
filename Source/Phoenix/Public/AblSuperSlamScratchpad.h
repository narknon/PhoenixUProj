#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSuperSlamScratchpad.generated.h"

class APhysicsConstraintActor;
class URagdollControlComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable, NonTransient)
class UAblSuperSlamScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicsConstraintActor* PhysicsConstraintActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URagdollControlComponent* RagdollControlComp;
    
    UAblSuperSlamScratchpad();
};

