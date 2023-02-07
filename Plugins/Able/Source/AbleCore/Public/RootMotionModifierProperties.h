#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ERootMotionModifierOrder.h"
#include "RootMotionModifierProperties.generated.h"

UCLASS(Abstract, Blueprintable)
class ABLECORE_API URootMotionModifierProperties : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERootMotionModifierOrder RootMotionModifierOrder;
    
    URootMotionModifierProperties();
};

