#pragma once
#include "CoreMinimal.h"
#include "AblCustomEventListenerStartEndTask.h"
#include "AblRootMotionModifiersEventListenerTask.generated.h"

class URootMotionModifierProperties;

UCLASS(Blueprintable, EditInlineNew)
class UAblRootMotionModifiersEventListenerTask : public UAblCustomEventListenerStartEndTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URootMotionModifierProperties*> RootMotionModifiers;
    
    UAblRootMotionModifiersEventListenerTask();
};

