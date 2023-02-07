#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablWandCastComboResetTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablWandCastComboResetTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetWandCastState;
    
public:
    UablWandCastComboResetTask();
};

