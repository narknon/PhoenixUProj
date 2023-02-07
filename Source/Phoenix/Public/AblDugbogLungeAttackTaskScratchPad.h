#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "UObject/NoExportTypes.h"
#include "AblDugbogLungeAttackTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblDugbogLungeAttackTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector AwayVector;
    
    UAblDugbogLungeAttackTaskScratchPad();
};

