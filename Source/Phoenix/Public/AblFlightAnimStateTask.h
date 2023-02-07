#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblFlightAnimStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblFlightAnimStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsGliding;
    
    UAblFlightAnimStateTask();
};

