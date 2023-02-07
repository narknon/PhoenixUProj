#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "RootMotionModifierProperties_Strafe.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_Strafe : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Acceleration;
    
    URootMotionModifierProperties_Strafe();
};

