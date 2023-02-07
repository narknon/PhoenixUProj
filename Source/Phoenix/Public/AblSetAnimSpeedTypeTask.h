#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAnimSpeedType.h"
#include "AblSetAnimSpeedTypeTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetAnimSpeedTypeTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAnimSpeedType::Type> AnimSpeedType;
    
public:
    UAblSetAnimSpeedTypeTask();
};

