#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "RootMotionModifierProperties_Dueling.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_Dueling : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HorizontalRootMotionAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalRootMotionAmount;
    
    URootMotionModifierProperties_Dueling();
};

