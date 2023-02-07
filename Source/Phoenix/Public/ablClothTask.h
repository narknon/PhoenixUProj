#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablClothTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablClothTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableClothSimulation;
    
public:
    UablClothTask();
};

