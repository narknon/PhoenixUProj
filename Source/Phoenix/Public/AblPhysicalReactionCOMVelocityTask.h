#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblNpcReactCapsuleImpulseVelocitySource.h"
#include "AblPhysicalReactionCOMVelocityTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblPhysicalReactionCOMVelocityTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblNpcReactCapsuleImpulseVelocitySource VelocitySource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Magnitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Angle;
    
    UAblPhysicalReactionCOMVelocityTask();
};

