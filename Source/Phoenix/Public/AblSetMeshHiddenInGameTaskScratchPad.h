#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSetMeshHiddenInGameTaskScratchPad.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable, NonTransient)
class UAblSetMeshHiddenInGameTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool OriginalHiddenValue;
    
    UAblSetMeshHiddenInGameTaskScratchPad();
};

