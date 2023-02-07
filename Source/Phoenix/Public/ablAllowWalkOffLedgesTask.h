#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablAllowWalkOffLedgesTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablAllowWalkOffLedgesTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowWalkOffLedges;
    
    UablAllowWalkOffLedgesTask();
};

