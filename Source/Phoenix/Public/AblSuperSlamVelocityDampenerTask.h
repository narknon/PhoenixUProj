#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSuperSlamVelocityDampenerTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSuperSlamVelocityDampenerTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngularVelocityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LinearVelocityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngularDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LinearDamping;
    
    UAblSuperSlamVelocityDampenerTask();
};

