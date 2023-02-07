#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblPlayDialogTaskScratchPad.generated.h"

class UAudioComponent;

UCLASS(Blueprintable, NonTransient)
class UAblPlayDialogTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UAudioComponent>> AttachedDialogs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 DialogEventId;
    
    UAblPlayDialogTaskScratchPad();
};

