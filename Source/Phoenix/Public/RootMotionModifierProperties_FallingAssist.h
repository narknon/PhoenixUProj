#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "RootMotionModifierProperties_FallingAssist.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_FallingAssist : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpToZero;
    
    URootMotionModifierProperties_FallingAssist();
};

