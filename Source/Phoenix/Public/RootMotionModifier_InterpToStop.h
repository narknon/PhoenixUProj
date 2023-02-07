#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_InterpToStop.generated.h"

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_InterpToStop : public URootMotionModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StartSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float InterpTime;
    
    URootMotionModifier_InterpToStop();
};

