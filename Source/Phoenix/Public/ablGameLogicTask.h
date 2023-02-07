#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "Name_GameLogicVarBool.h"
#include "Name_GameLogicVarInt32.h"
#include "ablGameLogicTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablGameLogicTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool BoolVar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarInt32 Int32Var;
    
public:
    UablGameLogicTask();
};

