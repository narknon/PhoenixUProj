#pragma once
#include "CoreMinimal.h"
#include "AblNpcPopupScratchpad.h"
#include "AblNpcReactPopupScratchpad.generated.h"

class UAblReactionData;

UCLASS(Blueprintable, NonTransient)
class UAblNpcReactPopupScratchpad : public UAblNpcPopupScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblReactionData* ReactionData;
    
    UAblNpcReactPopupScratchpad();
};

