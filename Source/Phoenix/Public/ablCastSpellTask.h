#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablCastSpellTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablCastSpellTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Socket;
    
public:
    UablCastSpellTask();
};

