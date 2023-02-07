#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AlphaBlend.h"
#include "AblTransformMultiChildTask.h"
#include "AblApplyTransformMultiChildTask.generated.h"

class UAblTaskCondition;

UCLASS(Blueprintable, EditInlineNew)
class UAblApplyTransformMultiChildTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachPointName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblTaskCondition*> TaskConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAblTransformMultiChildTask> ChildTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RestoreValueOnEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAlphaBlend BlendOut;
    
    UAblApplyTransformMultiChildTask();
};

