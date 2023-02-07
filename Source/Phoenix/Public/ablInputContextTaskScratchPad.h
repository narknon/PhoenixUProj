#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablInputContextTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablInputContextTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bAllowModifyContexts;
    
    UablInputContextTaskScratchPad();
    UFUNCTION(BlueprintCallable)
    void LeafNodeSwitched();
    
};

