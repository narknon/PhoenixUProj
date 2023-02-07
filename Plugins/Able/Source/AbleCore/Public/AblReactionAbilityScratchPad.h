#pragma once
#include "CoreMinimal.h"
#include "AblAbilityBaseScratchPad.h"
#include "AblReactionBranchDelegateDelegate.h"
#include "AblReactionContextDelegateDelegate.h"
#include "AblReactionAbilityScratchPad.generated.h"

class UAblReactionData;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblReactionAbilityScratchPad : public UAblAbilityBaseScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblReactionData* ReactionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblReactionContextDelegate OnReactionAbilityStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblReactionContextDelegate OnReactionAbilityInterrupt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblReactionContextDelegate OnReactionAbilityEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblReactionBranchDelegate OnReactionAbilityBranched;
    
    UAblReactionAbilityScratchPad();
};

