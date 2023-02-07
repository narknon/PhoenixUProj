#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "Templates/SubclassOf.h"
#include "AblGameLogicSwitchBranchTaskScratchPad.generated.h"

class UAblAbility;
class UGameLogicBoolBase;

UCLASS(Blueprintable, NonTransient)
class UAblGameLogicSwitchBranchTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UGameLogicBoolBase*> BoolResults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAblAbility>> Abilities;
    
    UAblGameLogicSwitchBranchTaskScratchPad();
};

