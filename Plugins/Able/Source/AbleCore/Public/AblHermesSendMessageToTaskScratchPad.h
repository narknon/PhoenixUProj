#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "HermesSendMessageToTaskEntry.h"
#include "AblHermesSendMessageToTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblHermesSendMessageToTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FHermesSendMessageToTaskEntry> InProgressMessage;
    
    UAblHermesSendMessageToTaskScratchPad();
};

