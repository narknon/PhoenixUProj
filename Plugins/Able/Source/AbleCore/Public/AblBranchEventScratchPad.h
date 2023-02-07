#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "AblAbilityEventScratchPad.h"
#include "AblBranchEventScratchPad.generated.h"

class UAblAbility;

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblBranchEventScratchPad : public UAblAbilityEventScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAblAbility* BranchAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FKey> CachedKeys;
    
    UAblBranchEventScratchPad();
};

