#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblCameraStackContextOperation.h"
#include "AblCameraStackContextTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCameraStackContextTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblCameraStackContextOperation TaskStartOperation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblCameraStackContextOperation TaskEndOperation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ContextName;
    
    UAblCameraStackContextTask();
};

