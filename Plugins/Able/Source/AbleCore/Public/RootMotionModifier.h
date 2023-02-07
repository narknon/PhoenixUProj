#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ERootMotionModifierOrder.h"
#include "RootMotionModifier.generated.h"

class AActor;
class URootMotionModifierProperties;

UCLASS(Abstract, Blueprintable, Transient)
class ABLECORE_API URootMotionModifier : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URootMotionModifierProperties* RootMotionModifierProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERootMotionModifierOrder RootMotionModifierOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    URootMotionModifier();
};

