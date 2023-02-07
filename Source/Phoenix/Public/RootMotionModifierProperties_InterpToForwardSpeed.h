#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "ERootMotModDesiredSpeed.h"
#include "RootMotionModifierProperties_InterpToForwardSpeed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_InterpToForwardSpeed : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERootMotModDesiredSpeed::Type> DesiredSpeedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    URootMotionModifierProperties_InterpToForwardSpeed();
};

