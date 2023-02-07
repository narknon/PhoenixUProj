#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ENPC_DilateSource.h"
#include "AblNPC_DilateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_DilateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_DilateSource Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DilationParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DilationTime;
    
public:
    UAblNPC_DilateTask();
};

