#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "InputContextWithType.h"
#include "EContextTaskOperationType.h"
#include "ablInputContextTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablInputContextTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputContextWithType> Contexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EContextTaskOperationType::Type> ContextTaskOperation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyDoOperationDuringCombatMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyDoOperationInNonCombatMode;
    
public:
    UablInputContextTask();
};

