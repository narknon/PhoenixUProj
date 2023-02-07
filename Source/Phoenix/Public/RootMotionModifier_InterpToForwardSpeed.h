#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_InterpToForwardSpeed.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_InterpToForwardSpeed : public URootMotionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentSpeed;
    
    URootMotionModifier_InterpToForwardSpeed();
};

