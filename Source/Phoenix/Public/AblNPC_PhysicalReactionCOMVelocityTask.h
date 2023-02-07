#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblNpcReactCapsuleImpulseVelocitySource.h"
#include "AblNPC_PhysicalReactionCOMVelocityTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_PhysicalReactionCOMVelocityTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblNpcReactCapsuleImpulseVelocitySource VelocitySource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Magnitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Angle;
    
    UAblNPC_PhysicalReactionCOMVelocityTask();
};

